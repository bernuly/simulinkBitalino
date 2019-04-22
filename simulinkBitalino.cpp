/*
 * File: simulinkBitalino.cpp
 *
 *
 *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
 *
 *   This file is an S-function produced by the S-Function
 *   Builder which only recognizes certain fields.  Changes made
 *   outside these fields will be lost the next time the block is
 *   used to load, edit, and resave this file. This file will be overwritten
 *   by the S-function Builder block. If you want to edit this file by hand, 
 *   you must change it only in the area defined as:  
 *
 *        %%%-SFUNWIZ_defines_Changes_BEGIN
 *        #define NAME 'replacement text' 
 *        %%% SFUNWIZ_defines_Changes_END
 *
 *   DO NOT change NAME--Change the 'replacement text' only.
 *
 *   For better compatibility with the Simulink Coder, the
 *   "wrapper" S-function technique is used.  This is discussed
 *   in the Simulink Coder's Manual in the Chapter titled,
 *   "Wrapper S-functions".
 *
 *  -------------------------------------------------------------------------
 * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
 *  ------------------------------------------------------------------------- 
 *
 * Created: Mon Apr 22 14:54:44 2019
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME simulinkBitalino
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS            0

#define NUM_OUTPUTS           2
/* Output Port  0 */
#define OUT_PORT_0_NAME       outputAnalog
#define OUTPUT_0_WIDTH        1
#define OUTPUT_DIMS_0_COL     4
#define OUTPUT_0_DTYPE        real_T
#define OUTPUT_0_COMPLEX      COMPLEX_NO
#define OUT_0_FRAME_BASED     FRAME_NO
#define OUT_0_BUS_BASED       0
#define OUT_0_BUS_NAME        
#define OUT_0_DIMS            2-D
#define OUT_0_ISSIGNED        1
#define OUT_0_WORDLENGTH      8
#define OUT_0_FIXPOINTSCALING 1
#define OUT_0_FRACTIONLENGTH  3
#define OUT_0_BIAS            0
#define OUT_0_SLOPE           0.125
/* Output Port  1 */
#define OUT_PORT_1_NAME       outputDigital
#define OUTPUT_1_WIDTH        1
#define OUTPUT_DIMS_1_COL     4
#define OUTPUT_1_DTYPE        real_T
#define OUTPUT_1_COMPLEX      COMPLEX_NO
#define OUT_1_FRAME_BASED     FRAME_NO
#define OUT_1_BUS_BASED       0
#define OUT_1_BUS_NAME        
#define OUT_1_DIMS            2-D
#define OUT_1_ISSIGNED        1
#define OUT_1_WORDLENGTH      8
#define OUT_1_FIXPOINTSCALING 1
#define OUT_1_FRACTIONLENGTH  3
#define OUT_1_BIAS            0
#define OUT_1_SLOPE           0.125

#define NPARAMS               2
/* Parameter 0 */
#define PARAMETER_0_NAME      device
#define PARAMETER_0_DTYPE     uint16_T
#define PARAMETER_0_COMPLEX   COMPLEX_NO
/* Parameter 1 */
#define PARAMETER_1_NAME      samplingfrequency
#define PARAMETER_1_DTYPE     uint16_T
#define PARAMETER_1_COMPLEX   COMPLEX_NO

#define SAMPLE_TIME_0         INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES       1
#define DISC_STATES_IC        [0]
#define NUM_CONT_STATES       0
#define CONT_STATES_IC        [0]

#define SFUNWIZ_GENERATE_TLC  0
#define SOURCEFILES           "__SFB__simulinkBitalino_mycode.cpp__SFB__bitalino.cpp__SFB__c:\program Files\MATLAB\R2018b\sys\lcc64\lcc64\lib64\ws2_32.lib"
#define PANELINDEX            8
#define USE_SIMSTRUCT         0
#define SHOW_COMPILE_STEPS    0
#define CREATE_DEBUG_MEXFILE  0
#define SAVE_CODE_ONLY        0
#define SFUNWIZ_REVISION      3.0
/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"

#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)

#define IS_PARAM_UINT16(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsUint16(pVal))

extern void simulinkBitalino_Start_wrapper(real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1);
extern void simulinkBitalino_Outputs_wrapper(real_T *outputAnalog,
			real_T *outputDigital,
			const real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1);
extern void simulinkBitalino_Update_wrapper(real_T *outputAnalog,
			real_T *outputDigital,
			real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1);
extern void simulinkBitalino_Terminate_wrapper(real_T *xD,
			void **pW,
			const uint16_T *device, const int_T p_width0,
			const uint16_T *samplingfrequency, const int_T p_width1);
/*====================*
 * S-function methods *
 *====================*/
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlCheckParameters =============================================
 * Abstract:
 *     Verify parameter definitions and types.
 */
static void mdlCheckParameters(SimStruct *S)
{
    int paramIndex  = 0;
    bool invalidParam = false;
    /* All parameters must match the S-function Builder Dialog */

    {
        const mxArray *pVal0 = ssGetSFcnParam(S, 0);
        if (!IS_PARAM_UINT16(pVal0)) {
            invalidParam = true;
            paramIndex = 0;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal1 = ssGetSFcnParam(S, 1);
        if (!IS_PARAM_UINT16(pVal1)) {
            invalidParam = true;
            paramIndex = 1;
            goto EXIT_POINT;
        }
    }


    EXIT_POINT:
    if (invalidParam) {
        char parameterErrorMsg[1024];
        sprintf(parameterErrorMsg, "The data type and or complexity of parameter %d does not match the "
                "information specified in the S-function Builder dialog. "
                "For non-double parameters you will need to cast them using int8, int16, "
                "int32, uint8, uint16, uint32 or boolean.", paramIndex + 1);
        ssSetErrorStatus(S, parameterErrorMsg);
    }
    return;
}
#endif /* MDL_CHECK_PARAMETERS */
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS); /* Number of expected parameters */
    #if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) {
            return;
        }
    } else {
        return; /* Parameter mismatch will be reported by Simulink */
    }
    #endif

    ssSetArrayLayoutForCodeGen(S, SS_COLUMN_MAJOR);

    ssSetSimStateCompliance(S, DISALLOW_SIM_STATE);

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);


    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;

    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    /* Output Port 0 */
    outputDimsInfo.width = OUTPUT_0_WIDTH;
    ssSetOutputPortDimensionInfo(S, 0, &outputDimsInfo);
    ssSetOutputPortMatrixDimensions(S, 0, OUTPUT_0_WIDTH, OUTPUT_DIMS_0_COL);
    ssSetOutputPortFrameData(S, 0, OUT_0_FRAME_BASED);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);
    /* Output Port 1 */
    outputDimsInfo.width = OUTPUT_1_WIDTH;
    ssSetOutputPortDimensionInfo(S, 1, &outputDimsInfo);
    ssSetOutputPortMatrixDimensions(S, 1, OUTPUT_1_WIDTH, OUTPUT_DIMS_1_COL);
    ssSetOutputPortFrameData(S, 1, OUT_1_FRAME_BASED);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, OUTPUT_1_COMPLEX);
    ssSetNumPWork(S, 1);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    ssSetSimulinkVersionGeneratedIn(S, "9.2");

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME_0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    ssSetOffsetTime(S, 0, 0.0);
}
#define MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ========================================
 * Abstract:
 *    Initialize the states
 */
static void mdlInitializeConditions(SimStruct *S)
{
    real_T *xD = ssGetRealDiscStates(S);

    /* Warning: parameters not of type double used as IC will be replaced with 0.0 */

    xD[0] = 0;
}

#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)

static void mdlSetWorkWidths(SimStruct *S)
{

    const char_T *rtParamNames[] = {"P1","P2"};
    ssRegAllTunableParamsAsRunTimeParams(S, rtParamNames);

}

#endif

#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
/* Function: mdlStart =======================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
static void mdlStart(SimStruct *S)
{
    void **pW = ssGetPWork(S);
    real_T *xD = ssGetDiscStates(S);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const uint16_T *device = (const uint16_T *) mxGetData(PARAM_DEF0(S));
    const uint16_T *samplingfrequency = (const uint16_T *) mxGetData(PARAM_DEF1(S));
    
    simulinkBitalino_Start_wrapper(xD, pW, device, p_width0, samplingfrequency, p_width1);
}
#endif /*  MDL_START */

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    void **pW = ssGetPWork(S);
    real_T *outputAnalog = (real_T *) ssGetOutputPortRealSignal(S, 0);
    real_T *outputDigital = (real_T *) ssGetOutputPortRealSignal(S, 1);
    const real_T *xD = ssGetDiscStates(S);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const uint16_T *device = (const uint16_T *) mxGetData(PARAM_DEF0(S));
    const uint16_T *samplingfrequency = (const uint16_T *) mxGetData(PARAM_DEF1(S));
    
    simulinkBitalino_Outputs_wrapper(outputAnalog, outputDigital, xD, pW, device, p_width0, samplingfrequency, p_width1);

}

#define MDL_UPDATE  /* Change to #undef to remove function */
#if defined(MDL_UPDATE)
/* Function: mdlUpdate ======================================================
 * Abstract:
 *    This function is called once for every major integration time step.
 *    Discrete states are typically updated here, but this function is
 *    useful for performing any tasks that should only take place once per
 *    integration step.
 */
static void mdlUpdate(SimStruct *S, int_T tid)
{
    void **pW = ssGetPWork(S);
    real_T *outputAnalog = (real_T *) ssGetOutputPortRealSignal(S, 0);
    real_T *outputDigital = (real_T *) ssGetOutputPortRealSignal(S, 1);
    real_T *xD = ssGetDiscStates(S);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const uint16_T *device = (const uint16_T *) mxGetData(PARAM_DEF0(S));
    const uint16_T *samplingfrequency = (const uint16_T *) mxGetData(PARAM_DEF1(S));
    
    simulinkBitalino_Update_wrapper(outputAnalog, outputDigital, xD, pW, device, p_width0, samplingfrequency, p_width1);

}
#endif /* MDL_UPDATE */
/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
    void **pW = ssGetPWork(S);
    real_T *xD = ssGetDiscStates(S);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const uint16_T *device = (const uint16_T *) mxGetData(PARAM_DEF0(S));
    const uint16_T *samplingfrequency = (const uint16_T *) mxGetData(PARAM_DEF1(S));
    
    simulinkBitalino_Terminate_wrapper(xD, pW, device, p_width0, samplingfrequency, p_width1);

}


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif



