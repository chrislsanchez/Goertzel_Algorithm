/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : Goertzel_QE128
**     Processor   : MCF51QE128CLH
**     Component   : MCF51QE128_64
**     Version     : Component 01.010, Driver 01.12, CPU db: 3.00.080
**     Datasheet   : MCF51QE128RM, Rev. 3, 9/2007
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2017-10-10, 13:19, # CodeGen: 6
**     Abstract    :
**         This component "MCF51QE128_64" contains initialization of the
**         CPU and provides basic methods and events for CPU core
**         settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.12
** @brief
**         This component "MCF51QE128_64" contains initialization of the
**         CPU and provides basic methods and events for CPU core
**         settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */
#include "PTF.h"
#include "ADC.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

/* Global variables */
volatile far word SR_reg;              /* Current CCR register */
volatile byte SR_lock;


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MCF51QE128_64)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /* asm (HALT) */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MCF51QE128_64)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MCF51QE128_64)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  __initialize_hardware (component MCF51QE128_64)
**
**     Description :
**         Configure the basic system functions (timing, etc.).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab of the CPU component. !!! ***/


void __initialize_hardware(void)
{

  /*** !!! Here you can place your own code using property "User code before PE initialization" on the build options tab of the CPU component. !!! ***/

  /* ### MCF51QE128_64 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=0,WAITE=1,??=0,RSTOPE=0,BKGDPE=1,RSTPE=0 */
  setReg8(SOPT1, 0x52U);                
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,BGBE=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,??=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  setReg8(SPMSC2, 0x02U);               
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  clrReg8Bits(SPMSC3, 0x38U);           
  /* Initialization of CPU registers */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm {
    /* VBR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ADDRESS=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    clr.l d0
    movec d0,VBR
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,??=0,FSD=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    clr.l d0
    movec d0,CPUCR
  }
  /*lint -restore Enable MISRA rule (1.1) checking. */
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(unsigned char*)0x03FFU != 0xFFU) { /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(unsigned char*)0x03FFU; /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (unsigned char)((*(unsigned char*)0x03FEU) & (unsigned char)0x01U); /* Initialize ICSSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x06U);               /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  setReg8(ICSC2, 0x00U);               /* Initialization of the ICS control register 2 */ 
  while(ICSSC_IREFST == 0U) {          /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=2,DMX32=0 */
  clrSetReg8Bits(ICSSC, 0x60U, 0x80U); /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0U) != 0x80U) {    /* Wait until the FLL switches to High range DCO mode */
  }

  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code using property "User code after PE initialization" on the build options tab of the CPU component. !!! ***/

}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MCF51QE128_64)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* SCGC1: TPM3=1,TPM2=1,TPM1=1,ADC=1,IIC2=1,IIC1=1,SCI2=1,SCI1=1 */
  setReg8(SCGC1, 0xFFU);                
  /* SCGC2: ??=1,FLS=1,IRQ=1,KBI=1,ACMP=1,RTC=1,SPI2=1,SPI1=1 */
  setReg8(SCGC2, 0xFFU);                
  /* Common initialization of the CPU registers */
  /* PTASE: PTASE7=0,PTASE6=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  clrReg8Bits(PTASE, 0xDFU);            
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  setReg8(PTDSE, 0x00U);                
  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */
  setReg8(PTESE, 0x00U);                
  /* PTFSE: PTFSE7=0,PTFSE6=0,PTFSE5=0,PTFSE4=0,PTFSE3=0,PTFSE2=0,PTFSE1=0,PTFSE0=0 */
  setReg8(PTFSE, 0x00U);                
  /* PTGSE: PTGSE3=0,PTGSE2=0,PTGSE1=0,PTGSE0=0 */
  clrReg8Bits(PTGSE, 0x0FU);            
  /* PTHSE: PTHSE7=0,PTHSE6=0,PTHSE1=0,PTHSE0=0 */
  clrReg8Bits(PTHSE, 0xC3U);            
  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=0,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
  setReg8(PTADS, 0xDFU);                
  /* PTBDS: PTBDS7=1,PTBDS6=1,PTBDS5=1,PTBDS4=1,PTBDS3=1,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
  setReg8(PTBDS, 0xFFU);                
  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=1,PTCDS2=1,PTCDS1=1,PTCDS0=1 */
  setReg8(PTCDS, 0xFFU);                
  /* PTDDS: PTDDS7=1,PTDDS6=1,PTDDS5=1,PTDDS4=1,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
  setReg8(PTDDS, 0xFFU);                
  /* PTEDS: PTEDS7=1,PTEDS6=1,PTEDS5=1,PTEDS4=1,PTEDS3=1,PTEDS2=1,PTEDS1=1,PTEDS0=1 */
  setReg8(PTEDS, 0xFFU);                
  /* PTFDS: PTFDS7=1,PTFDS6=1,PTFDS5=1,PTFDS4=1,PTFDS3=1,PTFDS2=1,PTFDS1=1,PTFDS0=1 */
  setReg8(PTFDS, 0xFFU);                
  /* PTGDS: PTGDS7=0,PTGDS6=0,PTGDS5=0,PTGDS4=0,PTGDS3=1,PTGDS2=1,PTGDS1=1,PTGDS0=1 */
  setReg8(PTGDS, 0x0FU);                
  /* PTHDS: PTHDS7=1,PTHDS6=1,PTHDS5=0,PTHDS4=0,PTHDS3=0,PTHDS2=0,PTHDS1=1,PTHDS0=1 */
  setReg8(PTHDS, 0xC3U);                
  /* PTGDD: PTGDD7=1,PTGDD6=1,PTGDD5=1,PTGDD4=1 */
  setReg8Bits(PTGDD, 0xF0U);            
  /* PTHDD: PTHDD5=1,PTHDD4=1,PTHDD3=1,PTHDD2=1 */
  setReg8Bits(PTHDD, 0x3CU);            
  /* PTJDD: PTJDD7=1,PTJDD6=1,PTJDD5=1,PTJDD4=1,PTJDD3=1,PTJDD2=1,PTJDD1=1,PTJDD0=1 */
  setReg8(PTJDD, 0xFFU);                
  /* ### Shared modules init code ... */
  /* ### Init_GPIO "PTF" init code ... */
  PTF_Init();
  /* ### Init_ADC "ADC" init code ... */
  ADC_Init();
  /* INTC_WCR: ENB=0,??=0,??=0,??=0,??=0,MASK=0 */
  setReg8(INTC_WCR, 0x00U);             
  SR_lock = 0x00;
  /* Set initial interrupt priority 0 */
  asm {
    move.w SR,D0;
    andi.l #0xF8FF,D0;
    move.w D0,SR;
  }
}

/* Initialization of the CPU registers in FLASH */
/* NVPROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
static unsigned char NVPROT_INIT @0x0000040D = 0xFFU;
/* NVOPT: KEYEN1=0,KEYEN0=1,??=1,??=1,??=1,??=1,SEC1=1,SEC0=1 */
static unsigned char NVOPT_INIT @0x0000040F = 0x7FU;
/* END Cpu. */

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
