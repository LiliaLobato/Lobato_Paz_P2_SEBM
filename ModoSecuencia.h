/*
 * ModoSecuencia.h
 *
 *  Created on: 31/03/2019
 *      Author: best buy
 */

#ifndef MODOSECUENCIA_H_
#define MODOSECUENCIA_H_
//Modo arabe

#include "RGB.h"
#include "GPIO.h"
#include "PushButton.h"

#define SYSTEM_CLOCK (10500000U)
#define ONE_SEG_DELAY (4.0F)



void simon_dice(uint8_t max_count);
void simon_dice_init(void);


#endif /* MODOSECUENCIA_H_ */
