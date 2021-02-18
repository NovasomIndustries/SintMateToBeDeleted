/*
 * SintMateTouchProcess.c
 *
 *  Created on: Feb 10, 2021
 *      Author: fil
 */

#include "main.h"

uint32_t	settingsp, homep;

static uint32_t play_stop_button_check(void)
{
	if (( SystemVar.touch_x > TOUCH_X0AREA_PLAYPAUSE) &&
			( SystemVar.touch_x < TOUCH_X1AREA_PLAYPAUSE) &&
			( SystemVar.touch_y > TOUCH_Y0AREA_PLAYPAUSE) &&
			( SystemVar.touch_y < TOUCH_Y1AREA_PLAYPAUSE))
		return 1;
	return 0;
}

static uint32_t increase_button_check(void)
{
	if (( SystemVar.touch_x > TOUCH_X0AREA_INCREASE) &&
			( SystemVar.touch_x < TOUCH_X1AREA_INCREASE) &&
			( SystemVar.touch_y > TOUCH_Y0AREA_INCREASE) &&
			( SystemVar.touch_y < TOUCH_Y1AREA_INCREASE))
		return 1;
	return 0;
}

static uint32_t decrease_button_check(void)
{
	if (( SystemVar.touch_x > TOUCH_X0AREA_DECREASE) &&
			( SystemVar.touch_x < TOUCH_X1AREA_DECREASE) &&
			( SystemVar.touch_y > TOUCH_Y0AREA_DECREASE) &&
			( SystemVar.touch_y < TOUCH_Y1AREA_DECREASE))
		return 1;
	return 0;
}

static uint32_t settings_button_check(void)
{
	if (( SystemVar.touch_x > TOUCH_X0AREA_SETTINGS) &&
			( SystemVar.touch_x < TOUCH_X1AREA_SETTINGS) &&
			( SystemVar.touch_y > TOUCH_Y0AREA_SETTINGS) &&
			( SystemVar.touch_y < TOUCH_Y1AREA_SETTINGS))
		return 1;
	return 0;
}

static uint32_t home_button_check(void)
{
	if (( SystemVar.touch_x > TOUCH_X0AREA_HOME) &&
			( SystemVar.touch_x < TOUCH_X1AREA_HOME) &&
			( SystemVar.touch_y > TOUCH_Y0AREA_HOME) &&
			( SystemVar.touch_y < TOUCH_Y1AREA_HOME))
		return 1;
	return 0;
}


uint32_t SintMateTouchProcess(void)
{
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
			if ( SystemVar.DownCounter < DOWNCOUNTER_MAX-10 )
			{
				SystemVar.DownCounter /=10;
				SystemVar.DownCounter ++;
				SystemVar.DownCounter *=10;
			}
			SetCounter(SystemVar.DownCounter, ILI9341_GREEN);
			SystemVar.Session_DownCounter = SystemVar.DownCounter;
		}
		if (decrease_button_check() == 1)
		{
			if ( SystemVar.DownCounter >= 20 )
			{
				SystemVar.DownCounter /=10;
				SystemVar.DownCounter --;
				SystemVar.DownCounter *=10;
			}
			SetCounter(SystemVar.DownCounter, ILI9341_GREEN);
			SystemVar.Session_DownCounter = SystemVar.DownCounter;

		}
		if (settings_button_check() == 1)
		{
			settingsp++;
		}
		if (home_button_check() == 1)
		{
			homep++;
		}
	}
	return ret_val;
}
