/*
 * ModoSecuencia.c
 *
 *  Created on: 31/03/2019
 *      Author: best buy
 */


#include "ModoSecuencia.h"

void simon_dice_init(void)
{
	uint8_t count = 0;
	while(FALSE == get_sw3_flag())
	{
		if(TRUE == get_pbn_flag(PB1)) //Push button 1 presionado?
		{
			funcpointer[count];
			clear_pbn_flag(PB1);
		}
		if(TRUE == get_pbn_flag(PB2))  //Push button 2 presionado?
		{

			clear_pbn_flag(PB2);
		}
		if(TRUE == get_pbn_flag(PB3))  //Push button 3 presionado?
		{

			clear_pbn_flag(PB3);
		}
		if(TRUE == get_pbn_flag(PB4))  //Push button 4 presionado?
		{

			clear_pbn_flag(PB4);
		}
		if(TRUE == get_pbn_flag(PB5))  //Push button 5 presionado?
		{

			clear_pbn_flag(PB5);
		}
		if(TRUE == get_pbn_flag(PB6))  //Push button 6 presionado?
		{

			clear_pbn_flag(PB6);
		}
	}
}
