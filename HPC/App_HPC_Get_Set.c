#include "App_HPC_Get_Set.h"
#include <stdio.h>


/*************************************************************************************************
   FUNCTION DEFINITIONS SINGLE PEDAL DRIVE
*************************************************************************************************/

HPC_SPD_FEATURE_ENABLE_CMD_T HPC_SPD_HE_FeatureEnable_Command_Var		= HPC_SPD_FEATURE_ENABLE_CMD_T_DISABLE;
HPC_SPD_STATUS_T HPC_SPD_XH_ACTIVE_Status_var							= HPC_SPD_STATUS_T_DISABLED;
HPC_SPD_STATUS_T HPC_SPD_HI_Status_Var									= HPC_SPD_STATUS_T_DISABLED;

HPC_SPD_SUBSCRIPTION_STATUS_T HPC_SPD_TIH_Subscription_Status(void)
{
	printf("HPC_SPD_TIH_Subscription_Status : %d\n",HPC_SPD_TIH_Subscription_Status_var);
	return HPC_SPD_TIH_Subscription_Status_var;
}

HPC_SPD_ENABLE_REQUEST_T HPC_SPD_IH_EnabledByUser_Flag(void)
{
	printf("HPC_SPD_IH_EnabledByUser_Flag : %d\n",HPC_SPD_IH_EnabledByUser_Flag_var);
	return HPC_SPD_IH_EnabledByUser_Flag_var;
}

// Setter for received signals
void Set_SPD_TIH_Subscription_Status(int value) 
{
    HPC_SPD_TIH_Subscription_Status_var = value;
}

void Set_SPD_IH_EnabledByUser_Flag(int value) 
{
    HPC_SPD_IH_EnabledByUser_Flag_var = value;
}

HPC_SPD_STATUS_T HPC_SPD_XH_ACTIVE_Status(void)
{
	printf("HPC_SPD_XH_ACTIVE_Status : %d\n",HPC_SPD_XH_ACTIVE_Status_var);
	return HPC_SPD_XH_ACTIVE_Status_var;
}

void HPC_SPD_HE_FeatureEnable_Command(HPC_SPD_FEATURE_ENABLE_CMD_T command)
{
	printf("HPC_SPD_HE_FeatureEnable_Command : %d\n",command);
	HPC_SPD_HE_FeatureEnable_Command_Var = command;
}

void HPC_SPD_HI_Status(HPC_SPD_STATUS_T status)
{
	printf("HPC_SPD_HI_Status : %d\n",status);
	HPC_SPD_HI_Status_Var = status;
}

