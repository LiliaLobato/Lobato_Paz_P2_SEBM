/*
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Tarea8_4_80_WC_FTM.c
 * @brief   Application entry point.
 */
#include "MK64F12.h" /* include peripheral declarations */
#include "GPIO.h"
#include "FlexTimer.h"
#include "NVIC.h"
#include "stdint.h"
#include "Bits.h"
#include "PushButton.h"
#include "ManualMode.h"
#include "RGB.h"
#include "RGB_external.h"
//#include "GlobalFunctions.h"

/**
 * Output compare frequency = (bus clock)/(Prescaler(mod+1)). = 1.05MHz
 * Note that is the same frequency of the overflow flow.
 */



int main(void)
{
	PushButton_sw2_config();
	PushButton_sw3_config();
	/**Configuration function for FlexTimer*/
	FlexTimer_PWM_CA_Init();
	FlexTimer_PWM_Modify_Duty_Cycle(0, CH1);
	FlexTimer_PWM_Modify_Duty_Cycle(0, CH2);
	NVIC_set_basepri_threshold(PRIORITY_12);
	NVIC_enable_interrupt_and_priotity(PORTB_IRQ, PRIORITY_4);
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ, PRIORITY_4);
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ, PRIORITY_4);

	NVIC_global_enable_interrupts;

	PushButton_external_config(GPIO_B, bit_2, PTB2_MASK); //B0
	PushButton_external_config(GPIO_B, bit_3, PTB2_MASK); //B1
	PushButton_external_config(GPIO_B, bit_10, PTB2_MASK); //B2
	PushButton_external_config(GPIO_B, bit_11, PTB2_MASK); //B3
	PushButton_external_config(GPIO_B, bit_9, PTB2_MASK); //B4
	PushButton_external_config(GPIO_B, bit_19, PTB2_MASK); //B5
	PushButton_external_config(GPIO_B, bit_18, PTB2_MASK); //B6

	GPIO_callback_init(GPIO_B, &PushButton_external_handler);
	manual_RGB_change_value();

	while(1)
	{
		RGB_external_change_color(0, RGB_RED);
		FlexTimer_PWM_Modify_Duty_Cycle(255, RGB_GREEN);
		FlexTimer_PWM_Modify_Duty_Cycle(0, RGB_BLUE);
	}
	return 0;
}
