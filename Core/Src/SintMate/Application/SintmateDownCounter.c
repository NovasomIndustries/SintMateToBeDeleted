/*
 * SintmateDownCounter.c
 *
 *  Created on: Feb 9, 2021
 *      Author: fil
 */

#include "main.h"

DIGIT_BUFFERS		__attribute__ ((aligned (4)))	uint16_t	DigitsCounter[DIGIT_WIDTH*DIGIT_HEIGHT*3];
uint16_t		DownCounter,suppress_trailing_zero;

void Tim100MSec_callback(void)
{
	SystemVar.counter++;
	if ( SystemVar.counter >= 10 )
	{
		SystemVar.counter = 0;
		SystemVar.counter_flag = 1;
	}
}

static void compileDigitsCounter(uint32_t color)
{
uint32_t	i,j,xcount;
uint32_t 	h,t,u;  // hundreds,tens,units

	u = DownCounter%10;
	t = (DownCounter/10)%10;
	h = (DownCounter/100)%10;
	xcount = 0;
	for(j=0;j<DIGIT_HEIGHT;j++)
	{
		for(i=0;i<DIGIT_WIDTH;i++,xcount++)
		{
			if (( suppress_trailing_zero == 1 ) && ( h == 0 ))
			{
				DigitsCounter[xcount] = 0;
			}
			else
			{
				switch(color)
				{
				case	ILI9341_GREEN : DigitsCounter[xcount] = Green[h][j*DIGIT_WIDTH+i];break;
				case	ILI9341_RED   : DigitsCounter[xcount] = Red[h][j*DIGIT_WIDTH+i];break;
				case	ILI9341_YELLOW: DigitsCounter[xcount] = Yellow[h][j*DIGIT_WIDTH+i];break;
				}
			}
		}
		for(i=0;i<DIGIT_WIDTH;i++,xcount++)
		{
			if (( suppress_trailing_zero == 1 ) && ( h == 0 ) && ( t == 0 ))
			{
				DigitsCounter[xcount] = 0;
			}
			else
			{
				switch(color)
				{
				case	ILI9341_GREEN : DigitsCounter[xcount] = Green[t][j*DIGIT_WIDTH+i];break;
				case	ILI9341_RED   : DigitsCounter[xcount] = Red[t][j*DIGIT_WIDTH+i];break;
				case	ILI9341_YELLOW: DigitsCounter[xcount] = Yellow[t][j*DIGIT_WIDTH+i];break;
				}
			}
		}
		for(i=0;i<DIGIT_WIDTH;i++,xcount++)
		{
			switch(color)
			{
			case	ILI9341_GREEN : DigitsCounter[xcount] = Green[u][j*DIGIT_WIDTH+i];break;
			case	ILI9341_RED   : DigitsCounter[xcount] = Red[u][j*DIGIT_WIDTH+i];break;
			case	ILI9341_YELLOW: DigitsCounter[xcount] = Yellow[u][j*DIGIT_WIDTH+i];break;
			}
		}
	}
}

void SetCounter(uint32_t value, uint32_t color)
{
	DownCounter = value;
	compileDigitsCounter(color);
	ILI9341_DrawImage(DOWNCOUNTER_100_POSX, DOWNCOUNTER_POSY, DIGIT_WIDTH*3, DIGIT_HEIGHT-1, DigitsCounter);
}

void InitCounter(void)
{
	suppress_trailing_zero = 1;
	SetCounter(120,ILI9341_GREEN);
}

void IncrementCounter(void)
{
uint32_t	color = ILI9341_GREEN;
	DownCounter++;
	if ( DownCounter < 30 )
		color = ILI9341_YELLOW;
	if ( DownCounter < 10 )
		color = ILI9341_RED;
	SetCounter(DownCounter,color);
	if (DownCounter > 120 )
		DownCounter = 0;
}

void DecrementCounter(void)
{
uint32_t	color = ILI9341_GREEN;
	DownCounter--;
	if ( DownCounter < 115 )
		color = ILI9341_YELLOW;
	if ( DownCounter < 110 )
		color = ILI9341_RED;
	SetCounter(DownCounter,color);
	if (DownCounter == 0 )
		DownCounter = 120;
}

