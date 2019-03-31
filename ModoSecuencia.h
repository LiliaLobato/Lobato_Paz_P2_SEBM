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

void (*funcpointer[10])(void) =
{
		0,0,0,0,0,0,0,0,0,0,
};


void simon_dice_init(void);


#endif /* MODOSECUENCIA_H_ */
