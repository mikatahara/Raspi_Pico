/**
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */

#include <stdint.h>

typedef struct{
    uint8_t integer;
    uint8_t fract;
    uint16_t wrap;
} PWMTABLE;

extern PWMTABLE miditopwm[128];
