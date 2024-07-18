/**
 * noteonch.h
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */

#define NOTECHANNEL 4   // use 4h

void inittonegen();
int8_t sharchfee();
int8_t sharchnotech(uint8_t key);
void setnoteonkey(uint8_t ch, uint8_t key);
void setnoteoff(uint8_t ch);

