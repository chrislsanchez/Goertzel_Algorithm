/*
 * Misc.c
 *
 *  Created on: Juni, 2017
 *      Author: Christian
 */

#include "Misc.h"


void delay(unsigned int t) // retardo para el juego inexacto
{
	int i, j;
	for (i = 0; i < 128; i++) 
	{
		for (j = 0; j < t; j++){}
	}
}

void delay_tpm(unsigned int u)  /* TPM2CNT=6---106,81 us; TPM2CNT=1--0,476837us   ; TPM2CNT=65535--1 s  */
	{
  TPM1CNT=0;
	while(TPM2CNT<u)	
		{
		asm(nop);
		}
	}
