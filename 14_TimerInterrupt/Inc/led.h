/*
 * led.h
 *
 *  Created on: 28-Apr-2025
 *      Author: Spectrum RND
 */

#ifndef LED_H_
#define LED_H_
#include<stdint.h>
#include"rcc.h"
#define USER_LED1			(1U << 0)
#define USER_LED2			(1U << 7)
#define USER_LED3			(1U << 14)

#define GPIOB_CLK_EN		(1U << 1)

#define GREEN_LED				USER_LED1
#define BLUE_LED				USER_LED2
#define RED_LED					USER_LED3

typedef uint32_t ledType;

void all_led_ON(void);
void all_led_OFF(void);
void all_led_toggle(void);
void led_on(ledType led);
void led_off(ledType led);
void led_toggle(ledType led);
void led_init(void);
#endif /* LED_H_ */
