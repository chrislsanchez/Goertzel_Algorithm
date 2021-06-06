/* ###################################################################
**     Filename    : main.c
**     Project     : Goertzel_QE128
**     Processor   : MCF51QE128CLH
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2017-10-10, 11:32, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PTF.h"
#include "ADC.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MyIncludes.h"

/* Goertzel funtions  */

#include <stdio.h>
#include <math.h>

#define SAMPLE	byte

#define SAMPLING_RATE	316455.7	//316455.69 with debbuger for 50 samples
#define TARGET_FREQUENCY	24000.0	//20 kHz
#define N	50	//Block size
#define Orden	40	//Number of magnitude samples for low pass filtering


float coeff,Q1,Q2,sine,cosine,magnitudeSquared;//variables para calculo del algoritmo

const float pi=3.141592653589793;

int adc_read;
int index;
static int data[N];

byte j=0;
float promedio=0,promedio_prov=0;

double resultado;

void ResetGoertzel(void);
void InitGoertzel(void);
void ProcessSample(int sample);
void GetRealImag(float *realPart, float *imagPart);
float GetMagnitudeSquared(void);
int filtro (int orden) ;
void muestreo(void);

/* Call this routine before every "block" (size=N) of samples. */
void ResetGoertzel(void)
{
  Q2 = 0;
  Q1 = 0;
}

/* Call this once, to pre-compute the constants. */
void InitGoertzel(void)
{
  int	k;
  float	floatN;
  float	omega;

  floatN = (float) N;
  k = (int) (0.5 + ((floatN * TARGET_FREQUENCY) / SAMPLING_RATE));
  omega = (float)((2.0 * pi * k) / floatN);
  sine = (float)(sin(omega));
  cosine = (float)(cos(omega));
  coeff = (float)(2.0 * cosine);

//  printf("For SAMPLING_RATE = %f", SAMPLING_RATE);
//  printf(" N = %d", N);
//  printf(" and FREQUENCY = %f,\n", TARGET_FREQUENCY);
//  printf("k = %d and coeff = %f\n\n", k, coeff);

  ResetGoertzel();
}

/* Call this routine for every sample. */
void ProcessSample(int sample)
{
  float Q0;
  Q0 = coeff * Q1 - Q2 + (float) (sample);
  Q2 = Q1;
  Q1 = Q0;
}


void GetRealImag(float *realPart, float *imagPart)
{
  *realPart = (Q1 - Q2 * cosine);
  *imagPart = (Q2 * sine);
}



float GetMagnitudeSquared(void)
{
  float result;

  result = Q1 * Q1 + Q2 * Q2 - Q1 * Q2 * coeff;
  return result;
}


/* User includes (#include below this line is not maintained by Processor Expert) */


/*FUNCION PARA FILTRO MOVE AVERAGE*/
/*	El orden del filtro determina cuantas muestras se toman para realizar el promedio que suaviza la señal*/
int filtro (int orden) 
  {
  int q,salida_filtro;
  salida_filtro=0;  
  for(q=1;q<=orden;q++) 
    {
    //ADCSC1_ADCH=canal;//predeterminado
    while (ADCSC1_COCO==0)
    	{}
    salida_filtro+=ADCR;     
    }
  salida_filtro/=orden; 
  return salida_filtro;
  }



void muestreo(void){
	byte i;
	for (i=0;i<N;i++){
	    while (ADCSC1_COCO==0)
	    	{}
		data[i]=ADCR; 	
	}
}


 //promedio=0;
 //promedio_prov=0;

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/


  
  
  for(;;) { 
  	
	LED_f=1;
	muestreo();
	LED_f=0;
	
	
	// Process the samples 
		  for (index = 0; index < N; index++)
		  {
		    ProcessSample(data[index]);
		  }

		  // Do the "optimised Goertzel" processing 
		   magnitudeSquared = GetMagnitudeSquared();
		
		   
		   

		
		   
		ResetGoertzel();  
		
		
		//function  to take several values of the magnitude squared result to avoid noise in the reading
		if(j>=Orden){
			promedio=promedio_prov/Orden;
			resultado=(double)(promedio*promedio);
			promedio_prov=0;
			j=0;
		}
		else{
			promedio_prov=promedio_prov+magnitudeSquared;
			j++;
		}
		
		
		   if(resultado>=620000000000){//>=550000000000 for 20000  KHz and SAMPLING_RATE	650026.0
			   LED=1;
		   }
		   else{
			   LED=0;
		   }
	
	
	
  	
  	
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
