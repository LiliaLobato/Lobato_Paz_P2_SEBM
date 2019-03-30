/*
 * ManualMode.c
 *
 *  Created on: 30/03/2019
 *      Author: best buy
 */

#include "ManualMode.h"

void manual_RGB_change_value()
{
	uint8_t red_intensity = 128;
	uint8_t green_intensity = 128;
	uint8_t blue_intensity = 128;


	while(FALSE == get_sw2_flag())
	{
		if(TRUE == get_pbn_flag(PB1)) //Push button 1 presionado?
		{
			if(blue_intensity >= 230)
			{
				blue_intensity = 255;
			}
			else
			{
				blue_intensity = blue_intensity + 25; //Blue LED + 10% of intensity
			}
			clear_pbn_flag(PB1);
		}
		if(TRUE == get_pbn_flag(PB2))  //Push button 2 presionado?
		{
			if(blue_intensity <= 25)
			{
				blue_intensity = 0;
			}
			else
			{
				blue_intensity = blue_intensity-25; //Blue LED - 10% of intensity
			}
			clear_pbn_flag(PB2);
		}
		if(TRUE == get_pbn_flag(PB3))  //Push button 3 presionado?
		{
			if(red_intensity >= 230)
			{
				red_intensity = 255;
			}
			else
			{
				red_intensity = red_intensity + 25; //RED LED + 10% of intensity
			}
			clear_pbn_flag(PB3);
		}
		if(TRUE == get_pbn_flag(PB4))  //Push button 4 presionado?
		{
			if(red_intensity <= 25)
			{
				red_intensity = 0;
			}
			else
			{
				red_intensity = red_intensity-25; //RED LED - 10% of intensity
			}

			clear_pbn_flag(PB4);
		}
		if(TRUE == get_pbn_flag(PB5))  //Push button 5 presionado?
		{
			if(green_intensity >= 230)
			{
				green_intensity = 255;
			}
			else
			{
				green_intensity = green_intensity + 25; //GREEN LED + 10% of intensity
			}
			clear_pbn_flag(PB5);
		}
		if(TRUE == get_pbn_flag(PB6))  //Push button 6 presionado?
		{
			if(green_intensity <= 25)
			{
				green_intensity = 0;
			}
			else
			{
				green_intensity = green_intensity-25; //GREEN LED - 10% of intensity
			}

			clear_pbn_flag(PB6);
		}

		FlexTimer_PWM_Modify_Duty_Cycle((red_intensity), CH0); //update Blue LED intensity
		FlexTimer_PWM_Modify_Duty_Cycle((green_intensity), CH1); //update Blue LED intensity
		FlexTimer_PWM_Modify_Duty_Cycle((blue_intensity), CH2); //update Blue LED intensity
	}

}
