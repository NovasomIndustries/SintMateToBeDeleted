/*
 * ws2812b.c
 *
 *  Created on: Dec 23, 2020
 *      Author: fil
 */
#include "main.h"
#include "ws2812b.h"

DIGIT_BUFFERS	__attribute__	((aligned (16)))	uint32_t	FrameBuffer[BUFLEN][LEDBPP]; /* 0GRB */

uint32_t WS2812_led_index_from_number(uint32_t led_number)
{
	return led_number*LEDBPP;
}

void WS2812_WritePixel(uint32_t location, uint8_t r,uint8_t g,uint8_t b)
{
int16_t	i,k;
	for(i=0,k=7;i<8;i++,k--)
	{
		if ( (g & (1 << i)) != 0 )
			FrameBuffer[location][k] = PATTERN_1;
		else
			FrameBuffer[location][k] = PATTERN_0;
		if ( (r & (1 << i)) != 0 )
			FrameBuffer[location][k+8] = PATTERN_1;
		else
			FrameBuffer[location][k+8] = PATTERN_0;
		if ( (b & (1 << i)) != 0 )
			FrameBuffer[location][k+16] = PATTERN_1;
		else
			FrameBuffer[location][k+16] = PATTERN_0;
	}
	HAL_TIM_PWM_Start_DMA(&LED_TIMER, LED_TIMER_CHANNEL,(uint32_t *)FrameBuffer,BUFLEN);
}

void WS2812_LedsOff(void)
{
int16_t	i,k,location;
	for(location=0;location<NUMLEDS;location++)
	{
		for(i=0,k=7;i<8;i++,k--)
		{
			FrameBuffer[location][k] = PATTERN_0;
			FrameBuffer[location][k+8] = PATTERN_0;
			FrameBuffer[location][k+16] = PATTERN_0;
		}
	}
}
