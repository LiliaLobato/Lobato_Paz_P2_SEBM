/*
 * ModoSecuencia.c
 *
 *  Created on: 31/03/2019
 *      Author: best buy
 */


#include "ModoSecuencia.h"
#include "RGB_external.h"
#include "PIT.h"
#include "NVIC.h"

void (*funcpointer[10])(void) =
{
		RGB_external_LEDS_off, RGB_external_LEDS_off, RGB_external_LEDS_off,
		RGB_external_LEDS_off, RGB_external_LEDS_off, RGB_external_LEDS_off,
		RGB_external_LEDS_off, RGB_external_LEDS_off ,RGB_external_LEDS_off, RGB_external_LEDS_off
};

void simon_dice_init(void)
{
	uint8_t count = 0;
	while((FALSE == get_sw3_flag()) && (count < 10))
	{
		if(TRUE == get_pbn_flag(PB1)) //Push button 1 presionado?
		{
			funcpointer[count] = RGB_external_BLUE_on;
			//pantalla_RGB_Secuencial(B1, count);
			count++;
			clear_pbn_flag(PB1);
		}
		if(TRUE == get_pbn_flag(PB2))  //Push button 2 presionado?
		{
			funcpointer[count] = RGB_external_RED_on;
			//pantalla_RGB_Secuencial(B2, count);
			count++;
			clear_pbn_flag(PB2);
		}
		if(TRUE == get_pbn_flag(PB3))  //Push button 3 presionado?
		{
			funcpointer[count] = RGB_external_GREEN_on;
			//pantalla_RGB_Secuencial(B3, count);
			count++;
			clear_pbn_flag(PB3);
		}
		if(TRUE == get_pbn_flag(PB4))  //Push button 4 presionado?
		{
			funcpointer[count] = RGB_external_YELLOW_on;
			//pantalla_RGB_Secuencial(B4, count);
			count++;
			clear_pbn_flag(PB4);
		}
		if(TRUE == get_pbn_flag(PB5))  //Push button 5 presionado?
		{
			funcpointer[count] = RGB_external_PURPLE_on;
			//pantalla_RGB_Secuencial(B5, count);
			count++;
			clear_pbn_flag(PB5);
		}
		if(TRUE == get_pbn_flag(PB6))  //Push button 6 presionado?
		{
			funcpointer[count] = RGB_external_WHITE_on;
			//pantalla_RGB_Secuencial(B6, count);
			count++;
			clear_pbn_flag(PB6);
		}
	}
	simon_dice(count);
}

void simon_dice(uint8_t max_count)
{
	uint8_t count = 0;
	PIT_clock_gating();
	PIT_enable();
	NVIC_enable_interrupt_and_priotity(PIT_CH2_IRQ, PRIORITY_4);

	NVIC_global_enable_interrupts;
	PIT_delay(PIT_2, SYSTEM_CLOCK, ONE_SEG_DELAY);
	PIT_enable_interrupt_2(PIT_2);

	while(FALSE == get_sw2_flag())
	{
		if(TRUE == PIT_get2_interrupt_flag_status())
		{
			if(count >= max_count)
			{
				count = 0;
			}
			funcpointer[count]();
			count++;
			PIT_clear2_interrupt_flag();
		}
	}

}
