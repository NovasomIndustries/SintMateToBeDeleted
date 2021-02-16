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
uint32_t	i;
	ILI9341_Init();
	ILI9341_FillScreen(ILI9341_BLACK);
	HAL_TIM_PWM_Start(&BACKLIGHT_TIMER, BACKLIGHT_TIMER_CHANNEL);
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
#else
	StoreDigitsInFlash();
#endif
	GetDigitsFromFlash();
#ifndef	WRITE
	ILI9341_DrawImage(0, 0, LOGO_WIDTH, LOGO_HEIGHT-1, SintmateLogo);
	while(SystemVar.lcd_dma_busy == 1);

	SystemVar.Session_DownCounter = INITIAL_DOWNCOUNTER_VALUE;
	SystemVar.run_state = RUN_STATE_IDLE;

	for(i=0;i<10;i++)
		bzero(Green[i],DIGIT_SIZE*2);

	InitCounter();
	DrawIdleButtons();
	StepperInit();
	WS2812_LedsOff();
	HAL_TIM_Base_Start_IT(&TICK100MS_TIMER);
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
	if ( SystemVar.usb_packet_ready == 1 )
	{
		USB_ImageUploader();
		SystemVar.usb_packet_ready = 0;
	}

#endif
}

