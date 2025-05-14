/*
 * File: HPC_SinglePedalDrive.c
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

#include "HPC_SinglePedalDrive.h"
#include "App_HPC_Get_Set.h"
#include "HPC_SinglePedalDrive_types.h"
#include <stdio.h>

/* Real-time model */
static HPC_SinglePedalDrive_RT_MODEL HPC_SinglePedalDrive_M_;
HPC_SinglePedalDrive_RT_MODEL *const HPC_SinglePedalDrive_M =
  &HPC_SinglePedalDrive_M_;

/* Model step function */
void HPC_SinglePedalDrive_step(void)
{
  printf("\nHPC_SinglePedalDrive_step called----------------->\n");
  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/SPD_IH_EnabledByUser_Flag'
   *  Inport: '<Root>/SPD_TIH_Subscription_Status'
   *  Logic: '<S1>/AND'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   */
  if ((HPC_SPD_TIH_Subscription_Status() == HPC_SPD_SUBSCRIPTION_STATUS_T_ACTIVE)
      && (HPC_SPD_IH_EnabledByUser_Flag() == HPC_SPD_ENABLE_REQUEST_T_ENABLE)) 
  {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     */
    printf("\n Set FeatureEnable_Command to Enable the Feature .......\n");
    HPC_SPD_HE_FeatureEnable_Command(HPC_SPD_FEATURE_ENABLE_CMD_T_ENABLE);
  } 
  else 
  {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    HPC_SPD_HE_FeatureEnable_Command(HPC_SPD_FEATURE_ENABLE_CMD_T_DISABLE);
  }

  /* End of Switch: '<S1>/Switch' */

  /* SignalConversion: '<S1>/Signal Copy1' incorporates:
   *  Inport: '<Root>/SPD_EH_Status'
   */
  HPC_SPD_HI_Status(HPC_SPD_XH_ACTIVE_Status());
}

/* Model initialize function */
void HPC_SinglePedalDrive_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void HPC_SinglePedalDrive_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
