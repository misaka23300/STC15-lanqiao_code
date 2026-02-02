#include "main.h"

enum {
  SONIC_TIME = 1000,
  KEY_TIME = 20,
};

sonic_t sonic;
key_t key;

void key_task() {
  if (key.press == 4) {
    if (sonic.mode == 1) {
      sonic.mode = 2;
      set_seg(7, 2);
    } else if (sonic.mode == 2) {
      sonic.mode = 1;
      set_seg(7, 1);
    }
  }
}

void sonic_task() {
  if (sonic.mode == 1) {
    sonic.distance = sonic_measure_mode1();
  } else if (sonic.mode == 2) {
    sonic.distance = sonic_measure_mode2();
  }

  set_seg(0, sonic.distance / 100 % 10);
  set_seg(1, sonic.distance / 10 % 10);
  set_seg(2, sonic.distance % 10);

  set_seg(3, 17);
  set_seg(4, 17);
  set_seg(5, 17);
  set_seg(6, 17);
}
void main() {
  boot_init();
  sonic.mode = 1;
  set_seg(7, 1);
  while (1) {

    if (sonic.time == SONIC_TIME) {
      sonic.time = 0;
      sonic_task();
    }

    if (key.time == KEY_TIME) {
      key.time = 0;
      key.press = key_scan();
      key_task();
    }
  }
}

void Timer2_Isr(void) interrupt 12 {
  seg_display();

  if (sonic.time < SONIC_TIME) {
    sonic.time++;
  }

  if (key.time < KEY_TIME) {
    key.time++;
  }
}
