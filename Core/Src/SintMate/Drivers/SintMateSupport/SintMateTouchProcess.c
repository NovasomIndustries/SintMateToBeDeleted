/*
 * SintMateTouchProcess.c
 *
 *  Created on: Feb 10, 2021
 *      Author: fil
 */

#include "main.h"

#ifndef	WRITE
static uint32_t play_stop_button_check(void)
{
	if (( SystemVar.touch_x > 32) && ( SystemVar.touch_x < 192) && ( SystemVar.touch_y < 128))
		return 1;
	return 0;
}

static uint32_t increase_button_check(void)
{
	if (( SystemVar.touch_x < 64) && ( SystemVar.touch_y > 128))
		return 1;
	return 0;
}

static uint32_t decrease_button_check(void)
{
	if (( SystemVar.touch_x > 192) && ( SystemVar.touch_y > 128))
		return 1;
	return 0;
}

uint32_t SintMateTouchProcess(void)
{
uint32_t 	h,t,u;  	// hundreds,tens,units
uint32_t	ret_val=0;	// returns 1 only if system changes state from stop to run

	if ( SystemVar.run_state == RUN_STATE_RUNNING)
	{
		if (play_stop_button_check() == 1)
		{
			SystemVar.run_state = RUN_STATE_IDLE;
			DoStepperStop();
			DrawIdleButtons();
		}
	}
	else
	{
		if (play_stop_button_check() == 1)
		{
			DoSteps();
			SystemVar.run_state = RUN_STATE_RUNNING;
			ret_val = 1;
			DrawPlayButtons();
		}
		if (increase_button_check() == 1)
		{
			u = 0;
			t = (SystemVar.DownCounter/10)%10;
			h = (SystemVar.DownCounter/100)%10;
			SystemVar.DownCounter = u + t*10 + h*100;
			if ( SystemVar.DownCounter < DOWNCOUNTER_MAX )
				SystemVar.DownCounter += 10;
			SetCounter(SystemVar.DownCounter, ILI9341_GREEN);
			SystemVar.Session_DownCounter = SystemVar.DownCounter;
		}
		if (decrease_button_check() == 1)
		{
			u = 0;
			t = (SystemVar.DownCounter/10)%10;
			h = (SystemVar.DownCounter/100)%10;
			SystemVar.DownCounter = u + t*10 + h*100;
			if ( SystemVar.DownCounter > 10 )
				SystemVar.DownCounter -= 10;
			SetCounter(SystemVar.DownCounter, ILI9341_GREEN);
			SystemVar.Session_DownCounter = SystemVar.DownCounter;

		}
	}
	return ret_val;
}
#endif
