/**
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */

#include "bsp/board.h"
#include "pico/stdlib.h"
#include "tusb.h"

/*------------- MAIN -------------*/
int main(void)
{
  uint8_t packet[4];
  board_init();
  stdio_init_all();

  // init device stack on configured roothub port
  tud_init(BOARD_TUD_RHPORT);

  while (1)
  {
    tud_task();                       // tinyusb device task
    while ( tud_midi_available() ){
      tud_midi_packet_read(packet);   // receive MIDI packet
      tud_midi_packet_write(packet);  // send MIDI packet
      printf("%02x %02x %02x %02x\n",packet[0],packet[1],packet[2],packet[3]);
    }
  }
  return 0;
}
