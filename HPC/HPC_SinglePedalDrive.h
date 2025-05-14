/*
 * File: HPC_SinglePedalDrive.h
 *
 * Code generated for Simulink model 'HPC_SinglePedalDrive'.
 *
 * Model version                  : 13.66
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec  3 14:37:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HPC_SinglePedalDrive_h_
#define RTW_HEADER_HPC_SinglePedalDrive_h_
#ifndef HPC_SinglePedalDrive_COMMON_INCLUDES_
#define HPC_SinglePedalDrive_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* HPC_SinglePedalDrive_COMMON_INCLUDES_ */

#include "HPC_SinglePedalDrive_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct HPC_SinglePedalDrive_tag_RTM {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void HPC_SinglePedalDrive_initialize(void);
extern void HPC_SinglePedalDrive_step(void);
extern void HPC_SinglePedalDrive_terminate(void);

/* Real-time Model object */
extern HPC_SinglePedalDrive_RT_MODEL *const HPC_SinglePedalDrive_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HPC_SinglePedalDrive'
 * '<S1>'   : 'HPC_SinglePedalDrive/Subsystem'
 * '<S2>'   : 'HPC_SinglePedalDrive/Subsystem/Compare To Constant1'
 * '<S3>'   : 'HPC_SinglePedalDrive/Subsystem/Compare To Constant4'
 */

/*-
 * Requirements for '<Root>': HPC_SinglePedalDrive

 */
#endif                                 /* RTW_HEADER_HPC_SinglePedalDrive_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
