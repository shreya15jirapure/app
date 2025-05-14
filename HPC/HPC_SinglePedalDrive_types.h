/*
 * File: HPC_SinglePedalDrive_types.h
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

#ifndef RTW_HEADER_HPC_SinglePedalDrive_types_h_
#define RTW_HEADER_HPC_SinglePedalDrive_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_HPC_SPD_SUBSCRIPTION_STATUS_T_
#define DEFINED_TYPEDEF_FOR_HPC_SPD_SUBSCRIPTION_STATUS_T_

typedef enum {
  HPC_SPD_SUBSCRIPTION_STATUS_T_INACTIVE = 0,/* Default value */
  HPC_SPD_SUBSCRIPTION_STATUS_T_ACTIVE
} HPC_SPD_SUBSCRIPTION_STATUS_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HPC_SPD_ENABLE_REQUEST_T_
#define DEFINED_TYPEDEF_FOR_HPC_SPD_ENABLE_REQUEST_T_

typedef enum {
  HPC_SPD_ENABLE_REQUEST_T_DISABLE = 0,/* Default value */
  HPC_SPD_ENABLE_REQUEST_T_ENABLE
} HPC_SPD_ENABLE_REQUEST_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HPC_SPD_STATUS_T_
#define DEFINED_TYPEDEF_FOR_HPC_SPD_STATUS_T_

typedef enum {
  HPC_SPD_STATUS_T_DISABLED = 0,       /* Default value */
  HPC_SPD_STATUS_T_ENABLED
} HPC_SPD_STATUS_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HPC_SPD_FEATURE_ENABLE_CMD_T_
#define DEFINED_TYPEDEF_FOR_HPC_SPD_FEATURE_ENABLE_CMD_T_

typedef enum {
  HPC_SPD_FEATURE_ENABLE_CMD_T_DISABLE = 0,/* Default value */
  HPC_SPD_FEATURE_ENABLE_CMD_T_ENABLE
} HPC_SPD_FEATURE_ENABLE_CMD_T;

#endif

/* Forward declaration for rtModel */
typedef struct HPC_SinglePedalDrive_tag_RTM HPC_SinglePedalDrive_RT_MODEL;

#endif                            /* RTW_HEADER_HPC_SinglePedalDrive_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
