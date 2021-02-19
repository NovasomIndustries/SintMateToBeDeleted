/*
 * SintMateSettings.c
 *
 *  Created on: Feb 19, 2021
 *      Author: fil
 */

#include "main.h"

#define	LINE_YPOS_DELTA	56
#define	TEXT_YPOS_DELTA	6
#define	NUM_LINES		4
#define	XGAP			8
#define	ICONS_YMAX		LINE_YPOS_DELTA*NUM_LINES

static void DrawIcons(uint32_t x0,uint32_t x1)
{
uint32_t	i;
	for(i=1;i<4;i++)
	{
		ILI9341_DrawImage(x0, i*LINE_YPOS_DELTA-8, ICONS_WIDTH, ICONS_HEIGHT-1, ArrowLeft);
		while(SystemVar.lcd_dma_busy == 1);
		ILI9341_DrawImage(x1, i*LINE_YPOS_DELTA-8, ICONS_WIDTH, ICONS_HEIGHT-1, ArrowRight);
		while(SystemVar.lcd_dma_busy == 1);
	}
	ILI9341_DrawImage(BACK_BUTTON_POSX, BACK_BUTTON_POSY, BACK_WIDTH, BACK_HEIGHT-1, Back);
	while(SystemVar.lcd_dma_busy == 1);
}

void SettingsEnter(void)
{
uint32_t	xpos=0,ypos=0,icon_xposl=0 , icon_xposr=ILI9341_WIDTH-ICONS_WIDTH;
char		message[32],yesno[4];
	ILI9341_FillScreen(ILI9341_BLACK);
	while(SystemVar.lcd_dma_busy == 1);
	xpos = ICONS_WIDTH+XGAP;
	ILI9341_WriteString(xpos, ypos+TEXT_YPOS_DELTA, "Settings", Font_16x26, ILI9341_BLUE, ILI9341_BLACK);
	ypos +=	LINE_YPOS_DELTA;
	sprintf(message,"RPM : %d",(int )SystemParameters.step_rpm);
	ILI9341_WriteString(xpos, ypos+TEXT_YPOS_DELTA, message, Font_11x18, ILI9341_BLUE, ILI9341_BLACK);
	ypos +=	LINE_YPOS_DELTA;
	sprintf(message,"Time : %d",(int )SystemParameters.max_running_time);
	ILI9341_WriteString(xpos, ypos+TEXT_YPOS_DELTA, message, Font_11x18, ILI9341_BLUE, ILI9341_BLACK);
	ypos +=	LINE_YPOS_DELTA;
	sprintf(yesno,"No ");
	sprintf(message,"Recalibrate touch : %s",yesno);
	ILI9341_WriteString(xpos, ypos+TEXT_YPOS_DELTA, message, Font_11x18, ILI9341_BLUE, ILI9341_BLACK);
	ypos +=	LINE_YPOS_DELTA;
	DrawIcons(icon_xposl,icon_xposr);
}

void SettingsLoop(void)
{

}

void SettingsExit(void)
{
	ILI9341_FillScreen(ILI9341_BLACK);
	while(SystemVar.lcd_dma_busy == 1);
	SystemVar.Session_DownCounter = INITIAL_DOWNCOUNTER_VALUE;
	ILI9341_DrawImage(0, 0, LOGO_WIDTH, LOGO_HEIGHT-1, SintmateLogo);
	while(SystemVar.lcd_dma_busy == 1);
	InitCounter();
	DrawIdleButtons();
	SystemVar.run_state = RUN_STATE_IDLE;

}
