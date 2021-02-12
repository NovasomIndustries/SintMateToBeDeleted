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
	SystemParameters.step_rpm = STEP_SPEED_RPM;
}

extern	uint16_t Logo[];

void Init_SintMate(void)
{
#ifndef	WRITE
char	NameVersion[32];
uint32_t	xpos;
	ILI9341_Init();
	ILI9341_FillScreen(ILI9341_BLACK);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	SetupFlash();
	//SystemParameters.touch_is_calibrated = 0;
	if ( SystemParameters.touch_is_calibrated == 0 )
	{
		HAL_TIM_Base_Start_IT(&htim7);
		ILI9341_calibrate_touch();
		StoreSettingsInFlash();
		HAL_TIM_Base_Stop_IT(&htim7);
		HAL_Delay(200);
	}
	/*
	sprintf(NameVersion,"V. %s",SintMateVERSION);
	xpos = (ILI9341_WIDTH - strlen(SintMateNAME)*16)/2;
	ILI9341_WriteString(xpos, LOGO_Y_POS, SintMateNAME, Font_16x26, ILI9341_BLUE, ILI9341_BLACK);
	xpos = (ILI9341_WIDTH - strlen(NameVersion)*11)/2;
	ILI9341_WriteString(xpos, LOGO_Y_POS+30, NameVersion, Font_11x18, ILI9341_BLUE, ILI9341_BLACK);
	*/

#else
	StoreDigitsInFlash();
#endif
	GetDigitsFromFlash();
#ifndef	WRITE
	ILI9341_DrawImage(0, 0, LOGO_WIDTH, LOGO_HEIGHT-1, SintmateLogo);
	while(SystemVar.lcd_dma_busy == 1);

	SystemVar.Session_DownCounter = INITIAL_DOWNCOUNTER_VALUE;
	SystemVar.run_state = RUN_STATE_IDLE;

	InitCounter();
	DrawIdleButtons();
	StepperInit();
	HAL_TIM_Base_Start_IT(&htim7);
#endif
}

void SintMateLoop(void)
{
#ifndef	WRITE
	if (( SystemVar.counter_flag == 1 ) && (SystemVar.run_state == RUN_STATE_RUNNING))
	{
		SystemVar.counter_flag = 0;
		DecrementCounter();
	}
	if ( SystemVar.touch_flag == 1 )
	{
		SystemVar.touch_flag = 0;
		if ( ILI9341_GetTouch(&SystemVar.touch_x,&SystemVar.touch_y) != 0 )
		{
			SintMateTouchProcess();
		}
	}
#endif
}

