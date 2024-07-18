/**
 * pwm.c
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */

#include "bsp/board.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "regtable.h"
#include "noteonch.h"
#include "pwm.h"

#define CHNUM   NOTECHANNEL
uint slice_num[CHNUM];

void pwm_set() {

    for(uint8_t i=0; i<CHNUM*2; i+=2){
        gpio_set_function(i,    GPIO_FUNC_PWM);
        gpio_set_function(i+1,  GPIO_FUNC_PWM);
    }

    for(uint8_t i=0; i<CHNUM; i++){
        slice_num[i] = pwm_gpio_to_slice_num(i*2);
    }
}

void pwm_on(uint8_t key){
    int8_t ch=sharchnotech(key);
    if(ch!=-1) return;
    ch=sharchfee(key);
    if(ch==-1) return;
    printf("Note ON=%d\n",ch);
    PWMTABLE *pt = &miditopwm[key];
    pwm_set_wrap(slice_num[ch], pt->wrap);
    pwm_set_clkdiv_int_frac(slice_num[ch], pt->integer,  pt->fract);
    pwm_set_chan_level(slice_num[ch], PWM_CHAN_A, pt->wrap>>1);
    pwm_set_chan_level(slice_num[ch], PWM_CHAN_B, pt->wrap>>2);
    pwm_set_enabled(slice_num[ch], true);
    setnoteonkey((uint8_t)ch,key);
}

void pwm_off(uint8_t key){
    int8_t ch=sharchnotech(key);
    if(ch==-1) return;
    printf("Note OFF=%d\n",ch);
    pwm_set_enabled(slice_num[ch], false);
    setnoteoff((uint8_t)ch);
}

void pwm_test(uint8_t ch, uint8_t key)
{
    PWMTABLE *pt = &miditopwm[key];
    pwm_set_wrap(slice_num[ch], pt->wrap);
    pwm_set_clkdiv_int_frac(slice_num[ch], pt->integer,  pt->fract);
    pwm_set_chan_level(slice_num[ch], PWM_CHAN_A, pt->wrap>>1);
    pwm_set_chan_level(slice_num[ch], PWM_CHAN_B, pt->wrap>>2);
    pwm_set_enabled(slice_num[ch], true);
}