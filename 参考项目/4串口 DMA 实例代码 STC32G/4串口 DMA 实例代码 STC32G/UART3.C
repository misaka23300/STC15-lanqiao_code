/*---------------------------------------------------------
UART3.C
----------------------------------------------------------*/
//主要收发函数使用说明:
/**
  * @功能  串口发送数据. 写数据至发送缓冲区(循环池), 写完立即返回, 由DMA管理数据流向串口, 用户无须关心. 只要缓冲区有足够的空间, 可持续写入数据
  * @参数  pt: 发送数据指针
  * @参数  Size: 发送数量(字节)
  * @返回值 当缓冲区没有足够的空间装入数据时返回1, 其它时候返回0
  * 原型: u8 UART3_Send( void *pt, u16 Size);
  */
  
  
/**
  * @功能  读串口数据, 从缓冲区内读取数据. (DMA接收数据后存放至接收缓冲区, 应用代码必须定时查询读取, 否则循环池发生数据覆盖, 会丢失一部分数据, 没有提示, 但不影响后续收发)
  * @参数  buf: 接收数据指针
  * @参数  Size: Size期盼接收的字节数
  * @返回值 实际接收字节数. 缓冲区空时(没有数据可读)返回0, 返回值<Size说明当读取完成后,缓冲区已空. 返回值==Size说明当读取完成后,缓冲区仍有数据可读. 任何时候,返回值不会大于Size
  * 原型: u16 UART3_Receive(u8 *buf, u16 Size);
  */

/*---------------------------------------------------------
文件包含
----------------------------------------------------------*/
#include "UART3.H"
#include ".\library\STC32G_Switch.H"
#include ".\library\STC32G_GPIO.h"

/*---------------------------------------------------------
发送部分定义及变量
----------------------------------------------------------*/
static u8 xdata  SEND_BUF[UART3_SEND_BUF_SIZE]; //数据池
static u16  SEND_APP_WR_ADDR=0; //结束指针
static u16  SEND_POINT=0;       //发送指针
static u16  SEND_SIZE =0;       //待发送字节数
static u16  SEND_DMA_SIZE =0;   //正在DMA处理的字节数
static bit  SEND_ENDBZ=1;       //结束标志

/*---------------------------------------------------------
接收部分定义及变量
----------------------------------------------------------*/
static u8 xdata  Receive_BUF[UART3_RECEIVE_BUF_SIZE];  //数据池
static u16  Receive_R_ADDR=0;   //数据读到此处的指针

    
/*---------------------------------------------------------
本地函数声明
----------------------------------------------------------*/
static u16 DmaUr3rDoneNu(void);
static void DMA_UART3_Init(void);

/**
  * @功能  初始化串口 初始化内容根据自身需求更改
  * @参数  btl: 指定波特率
  * @返回值 无
  */
void UART3_Init(u32 btl)
{
	P0_MODE_IO_PU(GPIO_Pin_0|GPIO_Pin_1);   //RXD TXD 设置为准双向口
    P0_PULL_UP_ENABLE(GPIO_Pin_1);          //TXD 4.1K上拉
    UART3_SW(UART3_SW_P00_P01);             //切换引脚
    
	S3CON = 0x10;		//8位数据,可变波特率
	S3CON &= 0xBF;		//串口3选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器时钟1T模式
	T2L = (65536-(MAIN_Fosc/4/btl));        //设置定时初始值
	T2H = (65536-(MAIN_Fosc/4/btl))>>8;     //设置定时初始值
	AUXR |= 0x10;		                    //定时器2开始计时
    
    ES3   = 0;                              //不开中断
    DMA_UART3_Init();                       //初始化DMA
}


/**
  * @功能  串口发送数据. 写数据至发送缓冲区(循环池), 写完立即返回, 由DMA管理数据流向串口, 用户无须关心. 只要缓冲区有足够的空间, 可持续写入数据
  * @参数  pt: 发送数据指针
  * @参数  Size: 发送数量(字节)
  * @返回值 当缓冲区没有足够的空间装入数据时返回1, 其它时候返回0
  */
u8 UART3_Send( void *pt, u16 Size)
{    
    u8 cpu_sr,*buf = pt;
    u16 end;
    
    if(Size == 0)return 0;
    if(UART3_GetCapacity()<Size) return 1;
    
    end = SEND_APP_WR_ADDR;
    
    if((end+Size)<UART3_SEND_BUF_SIZE){      //复制数据
        memcpy(&SEND_BUF[end],buf,Size);
        end+=Size;
    }
    else{
        u16 len = UART3_SEND_BUF_SIZE-end;
        memcpy(&SEND_BUF[end],buf,len);
        buf+=len;
        len=Size-len;
        memcpy(&SEND_BUF[0],buf,len);
        end=len;
    }
    
    OS_ENTER_CRITICAL();
    SEND_SIZE+=Size;
    SEND_APP_WR_ADDR = end;
    if(SEND_ENDBZ){
        SEND_ENDBZ=0;
        SEND_DMA_SIZE = (SEND_APP_WR_ADDR>SEND_POINT)? SEND_APP_WR_ADDR-SEND_POINT : UART3_SEND_BUF_SIZE-SEND_POINT;
        DMA_UR3T_AMTH = (SEND_DMA_SIZE-1)>>8;               //字节数
        DMA_UR3T_AMT  = (SEND_DMA_SIZE-1);                  //字节数
        DMA_UR3T_TXAH = (u16)(&SEND_BUF[SEND_POINT])>>8;    //地址
        DMA_UR3T_TXAL = (u16)(&SEND_BUF[SEND_POINT]);       //地址
        DMA_UR3T_CR   = 0XC0;                               //启动DMA
    }
    OS_EXIT_CRITICAL();
        
    return 0;
}

/**
  * @功能  读串口数据, 从缓冲区内读取数据. (DMA接收数据后存放至接收缓冲区, 应用代码必须定时查询读取, 否则循环池发生数据覆盖, 会丢失一部分数据, 没有提示, 但不影响后续收发)
  * @参数  buf: 接收数据指针
  * @参数  Size: Size期盼接收的字节数
  * @返回值 实际接收字节数. 缓冲区空时(没有数据可读)返回0, 返回值<Size说明当读取完成后,缓冲区已空. 返回值==Size说明当读取完成后,缓冲区仍有数据可读. 任何时候,返回值不会大于Size
  */
u16 UART3_Receive(u8 *buf, u16 Size)
{
    u16 w_addr,nu=0;
    if(Size==0)return 0;
    w_addr=DmaUr3rDoneNu();
    if(Receive_R_ADDR==w_addr)return 0;
    nu = (w_addr>Receive_R_ADDR)? w_addr-Receive_R_ADDR : w_addr+UART3_RECEIVE_BUF_SIZE-Receive_R_ADDR;
    nu = (nu<Size)? nu:Size;
    if((Receive_R_ADDR+nu)<UART3_RECEIVE_BUF_SIZE){
        memcpy(buf,&Receive_BUF[Receive_R_ADDR],nu);
        Receive_R_ADDR+=nu;
        return nu;
    }
    else{
        u16 len = UART3_RECEIVE_BUF_SIZE-Receive_R_ADDR;
        memcpy(buf,&Receive_BUF[Receive_R_ADDR],len);
        buf+=len;
        len=nu-len;
        memcpy(buf,&Receive_BUF[0],len);
        Receive_R_ADDR=len;
        return nu;
    }
}

/*---------------------------------------------------------
返回发送缓冲区剩余空间
----------------------------------------------------------*/
u16 UART3_GetCapacity( void )
{
    u8 cpu_sr;
    u16 s;
    OS_ENTER_CRITICAL();
    s = SEND_SIZE;
    OS_EXIT_CRITICAL();
    return UART3_SEND_BUF_SIZE-s;
}

/*---------------------------------------------------------
返回DMA_UR3R_DONE
----------------------------------------------------------*/
static u16 DmaUr3rDoneNu(void)
{
    u8 cpu_sr,a,b,c;
    OS_ENTER_CRITICAL();
    do{
        a = DMA_UR3R_DONEH;
        b = DMA_UR3R_DONE;
        c = DMA_UR3R_DONEH;
    }while(a!=c);
    OS_EXIT_CRITICAL();
    return ((u16)c<<8)+(u16)b;
}

/*---------------------------------------------------------
DMA_UART3_Init
----------------------------------------------------------*/
static void DMA_UART3_Init(void)            
{
    DMA_UR3T_STA = 0x00;                            //清除标志
	DMA_UR3T_CFG = 0x8A;		                    //允许DMA中断, 中断Priority_2优先级,传输Priority_2优先级
    
    DMA_UR3R_STA  = 0x00;                           //清除标志
    DMA_UR3R_AMTH = (UART3_RECEIVE_BUF_SIZE-1)>>8;	//字节数
    DMA_UR3R_AMT  = (UART3_RECEIVE_BUF_SIZE-1);	    //字节数		
    DMA_UR3R_RXAH = (u16)Receive_BUF>>8;            //地址
    DMA_UR3R_RXAL = (u16)Receive_BUF;               //地址
	DMA_UR3R_CFG  = 0x8A;		                    //允许DMA中断, 中断Priority_2优先级,传输Priority_2优先级
    DMA_UR3R_CR = 0XA1;                             //开DMA接收
}

/*---------------------------------------------------------
DMA_UART3TX中断
----------------------------------------------------------*/
void DMA_UART3TX_ISR_Handler(void) interrupt DMA_UR3T_VECTOR  
{
    DMA_UR3T_STA = 0;   //清除中断标志
    SEND_SIZE-=SEND_DMA_SIZE;   //发送数量递减
    SEND_POINT+=SEND_DMA_SIZE;  //发送指针递加
    if(SEND_POINT>=UART3_SEND_BUF_SIZE)SEND_POINT=0;//指针循环调整
    if(SEND_SIZE)   //如果有数据要发出
    {
        SEND_DMA_SIZE = (SEND_APP_WR_ADDR>SEND_POINT)? SEND_APP_WR_ADDR-SEND_POINT : UART3_SEND_BUF_SIZE-SEND_POINT;
        DMA_UR3T_AMTH = (SEND_DMA_SIZE-1)>>8;                //字节数
        DMA_UR3T_AMT  = (SEND_DMA_SIZE-1);                   //字节数
        DMA_UR3T_TXAH = (u16)(&SEND_BUF[SEND_POINT])>>8;     //地址
        DMA_UR3T_TXAL = (u16)(&SEND_BUF[SEND_POINT]);        //地址
        DMA_UR3T_CR   = 0XC0;                                //启动DMA
    }
    else{   //没有数据要发出,恢复到默认状态
        SEND_ENDBZ = 1;
        SEND_DMA_SIZE = SEND_POINT = SEND_APP_WR_ADDR = 0;  //此句非必要
    }
}

/*---------------------------------------------------------
DMA_UART3RX中断
----------------------------------------------------------*/
void DMA_UART3RX_ISR_Handler(void) interrupt DMA_UR3R_VECTOR  
{
    DMA_UR3R_STA = 0;   //清除中断标志
    DMA_UR3R_CR = 0XA1; //开DMA接收
}

