/*
 * StepperDriver.c
 *
 *  Created on: Feb 11, 2021
 *      Author: fil
 */


#include "main.h"

static	uint32_t	number_of_pulses;
static	uint32_t	step_number,pulses_per_second;

void StepperCallback(void)
{

}

void StepperInit(void)
{

}

void DoSteps(void)
{
	pulses_per_second = (NUM_STEPS_PER_ROTATION * SystemParameters.step_rpm) / 60; // that 60 is for second ...
	number_of_pulses = step_number*4 * SystemVar.DownCounter;
	HAL_TIM_OC_Start_DMA(&htim16, TIM_CHANNEL_1, &number_of_pulses, 32);
}

void DoNumberOfSteps(uint32_t steps)
{
	number_of_pulses = steps;
	HAL_TIM_OC_Start_DMA(&htim16, TIM_CHANNEL_1, &number_of_pulses, 32);
}

void DoStepperStop(void)
{
	HAL_TIM_OC_Stop_DMA(&htim16, TIM_CHANNEL_1);
}

