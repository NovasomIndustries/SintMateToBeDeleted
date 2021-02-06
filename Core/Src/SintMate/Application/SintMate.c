/*
 * SintMate.c
 *
 *  Created on: Feb 4, 2021
 *      Author: fil
 */
#include "main.h"

SystemParametersTypeDef	SystemParameters;
SystemVarDef			SystemVar;

void SintMate_SystemSetDefaults(void)
{
	bzero((uint8_t *)&SystemParameters,sizeof(SystemParameters));
	sprintf(SystemParameters.Header,SintMateNAME);
	sprintf(SystemParameters.Version,SintMateVERSION);
}

void Init_SintMate(void)
{
char	NameVersion[32];
uint32_t	xpos;
	SetupFlash();
	ILI9341_Init();
	ILI9341_FillScreen(ILI9341_BLACK);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	if ( SystemParameters.touch_is_calibrated == 0 )
	{
		ILI9341_calibrate_touch();
		StoreSettingsInFlash();
	}
	sprintf(NameVersion,"V. %s",SintMateVERSION);
	xpos = (ILI9341_WIDTH - strlen(SintMateNAME)*16)/2;
	ILI9341_WriteString(xpos, 2*10+2*18, SintMateNAME, Font_16x26, ILI9341_BLUE, ILI9341_BLACK);
	xpos = (ILI9341_WIDTH - strlen(NameVersion)*11)/2;
	ILI9341_WriteString(xpos, 4*10+4*18, NameVersion, Font_11x18, ILI9341_BLUE, ILI9341_BLACK);
	HAL_Delay(1000);
	//ILI9341_FillScreen(ILI9341_RED);
	//tempwritebkg(0);
	//ILI9341_FillScreen(ILI9341_BLACK);
	HAL_Delay(1000);
	LoadBackgroundImage(0);
}

