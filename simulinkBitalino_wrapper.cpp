
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <string>
#include <iostream>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 4

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
extern void myStart(real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1,
                        SimStruct *S);

extern void myUpdate(real_T *outputAnalog, real_T *outputDigital,
			real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1);

void myTerminate(real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void simulinkBitalino_Start_wrapper(real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */

myStart(xD, pW, device, p_width0, samplingfrequency, p_width1, S);
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void simulinkBitalino_Outputs_wrapper(real_T *outputAnalog,
			real_T *outputDigital,
			const real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void simulinkBitalino_Update_wrapper(real_T *outputAnalog,
			real_T *outputDigital,
			real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
 
myUpdate(outputAnalog, outputDigital, xD, pW, device, p_width0, samplingfrequency, p_width1);
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
void simulinkBitalino_Terminate_wrapper(real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */

myTerminate(xD, pW, device, p_width0, samplingfrequency, p_width1);
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

