/**
 * MIT License
 * Copyright (c) 2024 Mikatahara
 */


#include "bsp/board.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "regtable.h"

uint slice_num;

void pwm_set() {
    gpio_set_function(0, GPIO_FUNC_PWM);
    gpio_set_function(1, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(0);

    pwm_set_wrap(slice_num, 32938);
    pwm_set_clkdiv_int_frac(slice_num, 8, 10);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 16469);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 8234);
    pwm_set_enabled(slice_num, true);

}

void pwm_on(uint8_t key){
    PWMTABLE *pt = &miditopwm[key];
    pwm_set_wrap(slice_num, pt->wrap);
    pwm_set_clkdiv_int_frac(slice_num, pt->integer,  pt->fract);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, pt->wrap>>1);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, pt->wrap>>2);
    pwm_set_enabled(slice_num, true);
    printf("ON : %04x %02x %02x\n",pt->wrap, pt->integer, pt->fract);
}

void pwm_off(uint8_t key){
    PWMTABLE *pt = &miditopwm[key];
    pwm_set_wrap(slice_num, pt->wrap);
    pwm_set_clkdiv_int_frac(slice_num, pt->integer,  pt->fract);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 0);
    pwm_set_enabled(slice_num, false);
    printf("OFF: %04x %02x %02x\n",pt->wrap, pt->integer, pt->fract);
}
