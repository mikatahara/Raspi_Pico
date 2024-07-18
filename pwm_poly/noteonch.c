/**
 * noteonch.c
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */

#include "bsp/board.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "noteonch.h"

static short NoteREG[NOTECHANNEL];

void inittonegen()
{
  for(uint8_t i=0; i<NOTECHANNEL; i++){
    NoteREG[i]=-1;
  }
}

/* 空きチャンネルを探す */
int8_t sharchfee(){
  int8_t ch=-1;
  printf("%d %d %d %d\n",NoteREG[0],NoteREG[1],NoteREG[2],NoteREG[3]);
  for(uint8_t i=0; i<NOTECHANNEL; i++){
      if(NoteREG[i]==-1){
        ch=(int8_t)i;
        break;
      }
  }
  return ch;
}

/* key はどのチャンネルで鳴っている探す */
int8_t sharchnotech(uint8_t key){
  int8_t ch=-1;
  for(uint8_t i=0; i<NOTECHANNEL; i++){
      if(NoteREG[i]==key){
        ch=(int8_t)i;
        break;
      }
  }
  return ch;
}

void setnoteonkey(uint8_t ch, uint8_t key)
{
  NoteREG[ch]=key;
}

void setnoteoff(uint8_t ch)
{
  NoteREG[ch]=-1;
}
