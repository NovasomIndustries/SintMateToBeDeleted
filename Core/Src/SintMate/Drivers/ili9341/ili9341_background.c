/*
 * ili9341_background.c
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#include "main.h"

extern	uint16_t Red[10][DIGIT_SIZE];

void LoadBackgroundImage(uint16_t background_index)
{
	/*
	ILI9341_DrawImage(20, 180, DIGIT_WIDTH, DIGIT_HEIGHT-1, Red[0]);
	while ( SystemVar.lcd_dma_busy == 1 );
	ILI9341_DrawImage(20+DIGIT_WIDTH, 180, DIGIT_WIDTH, DIGIT_HEIGHT-1, Red[1]);
	while ( SystemVar.lcd_dma_busy == 1 );
	ILI9341_DrawImage(20+DIGIT_WIDTH+DIGIT_WIDTH, 180, DIGIT_WIDTH, DIGIT_HEIGHT-1, Red[9]);
	while ( SystemVar.lcd_dma_busy == 1 );
	*/
}

