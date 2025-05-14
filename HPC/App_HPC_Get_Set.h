#include "HPC_SinglePedalDrive_types.h"

/** Local Data **/
static HPC_SPD_SUBSCRIPTION_STATUS_T HPC_SPD_TIH_Subscription_Status_var        = HPC_SPD_SUBSCRIPTION_STATUS_T_ACTIVE;
static HPC_SPD_ENABLE_REQUEST_T HPC_SPD_IH_EnabledByUser_Flag_var				= HPC_SPD_ENABLE_REQUEST_T_DISABLE;
extern HPC_SPD_FEATURE_ENABLE_CMD_T HPC_SPD_HE_FeatureEnable_Command_Var;
extern HPC_SPD_STATUS_T HPC_SPD_HI_Status_Var									;
extern HPC_SPD_STATUS_T HPC_SPD_XH_ACTIVE_Status_var							;

/*************************************************************************************************
   FUNCTION DEFINITIONS SINGLE PEDAL DRIVE
*************************************************************************************************/

HPC_SPD_SUBSCRIPTION_STATUS_T HPC_SPD_TIH_Subscription_Status(void);

HPC_SPD_ENABLE_REQUEST_T HPC_SPD_IH_EnabledByUser_Flag(void);

void Set_SPD_TIH_Subscription_Status(int value);

void Set_SPD_IH_EnabledByUser_Flag(int value);

void HPC_SPD_HE_FeatureEnable_Command(HPC_SPD_FEATURE_ENABLE_CMD_T command);

void HPC_SPD_HI_Status(HPC_SPD_STATUS_T status);

HPC_SPD_STATUS_T HPC_SPD_XH_ACTIVE_Status(void);
