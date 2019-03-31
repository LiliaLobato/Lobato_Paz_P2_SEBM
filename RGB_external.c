/*
 * RGB_external.c
 *
 *  Created on: 31/03/2019
 *      Author: best buy
 */
#include "RGB_external.h"

void RGB_external_change_color(uint8_t intensity, RGB_LEDS color)
{
	FlexTimer_PWM_Modify_Duty_Cycle(intensity, color);
}
