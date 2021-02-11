/*
 * SintMateButtons.c
 *
 *  Created on: Feb 10, 2021
 *      Author: fil
 */

#include "main.h"

void DrawIdleButtons(void)
{
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(PLAYPAUSE_BUTTON_POSX, PLAYPAUSE_BUTTON_POSY, BUTTONS_WIDTH, BUTTONS_HEIGHT-1, play);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(INCREASE_BUTTON_POSX, INCREASE_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, increase);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(DECREASE_BUTTON_POSX, DECREASE_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, decrease);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(SETTINGS_BUTTON_POSX, SETTINGS_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, settings);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(HOME_BUTTON_POSX, HOME_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, home);
}

void DrawPlayButtons(void)
{
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(PLAYPAUSE_BUTTON_POSX, PLAYPAUSE_BUTTON_POSY, BUTTONS_WIDTH, BUTTONS_HEIGHT-1, stop);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(INCREASE_BUTTON_POSX, INCREASE_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, increase_disabled);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(DECREASE_BUTTON_POSX, DECREASE_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, decrease_disabled);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(SETTINGS_BUTTON_POSX, SETTINGS_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, settings_disabled);
	while(SystemVar.lcd_dma_busy == 1);
	ILI9341_DrawImage(HOME_BUTTON_POSX, HOME_BUTTON_POSY, ICONS_WIDTH, ICONS_HEIGHT-1, home_disabled);
}
