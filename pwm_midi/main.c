/**
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */

#include <stdint.h>

#include "bsp/board.h"
#include "pico/stdlib.h"
#include "tusb.h"

extern void pwm_set();
extern void pwm_on(uint8_t key);
extern void pwm_off(uint8_t key);

/*------------- MAIN -------------*/
int main(void)
{
  uint8_t packet[4];
  uint8_t status;
  uint8_t data1;
  uint8_t data2;

  board_init();
  stdio_init_all();
  pwm_set();

  // init device stack on configured roothub port
  tud_init(BOARD_TUD_RHPORT);

  while (1)
  {
    tud_task();                       // tinyusb device task
    while ( tud_midi_available() ){
      tud_midi_packet_read(packet);   // receive MIDI packet
      status = packet[1]&0xF0;
      data1 = packet[2];
      data2 = packet[3];

      printf("status = %02x\n",status);

      switch(status){
        case 0x80:  //Note Off
          printf("OFF\n");
          pwm_off(data1);
          break;
        case 0x90:  //Note On
          if(data2!=0) pwm_on(data1);
          else pwm_off(data1);
          break;
        case 0xA0:
          break;
        case 0xB0:
          break;
        case 0xC0:
          break;
        case 0xD0:
          break;
        case 0xE0:   //Pitch Bend
          break;
      }
      printf("%02x %02x %02x\n",status,data1,data2);
    }
  }

  return 0;
}
