/**************************************************************************//**
    2  * @file     core_cm4.c
    3  * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Source File
    4  * @version  V2.01
    5  * @date     06. December 2010
    6  *
    7  * @note
    8  * Copyright (C) 2010 ARM Limited. All rights reserved.
    9  *
   10  * @par
   11  * ARM Limited (ARM) is supplying this software for use with Cortex-M 
   12  * processor based microcontrollers.  This file can be freely distributed 
   13  * within development tools that are supporting such ARM based processors. 
   14  *
   15  * @par
   16  * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
   17  * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
   18  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
   19  * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
   20  * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
   21  *
   22  ******************************************************************************/
   
   /* ###################  Compiler specific Intrinsics  ########################### */
    
  #if defined ( __CC_ARM   ) /*------------------ RealView Compiler ----------------*/
   /* ARM armcc specific functions */
  
   

  #elif (defined (__ICCARM__)) /*------------------ ICC Compiler -------------------*/
   /* IAR iccarm specific functions */
  
 
 
    #elif (defined (__GNUC__)) /*------------------ GNU Compiler ---------------------*/
 /* GNU gcc specific functions */
 

 
 #elif (defined (__TASKING__)) /*------------------ TASKING Compiler --------------*/
 /* TASKING carm specific functions */

 /*
   48  * The CMSIS functions have been implemented as intrinsics in the compiler.
   49  * Please use "carm -?i" to get an up to date list of all instrinsics,
   50  * Including the CMSIS ones.
   51  */
  
 #endif
 

