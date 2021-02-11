/*
 * flash_manager.c
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#include "main.h"

/*
 * Each sector is 4096 bytes
 * Sector 0 : header + setup data , see SystemParametersTypeDef
 * Sector 1 : program
 * Sector 2..f :	Unused
 * Sector 10..11	:	Digit 0 red
 * Sector 12..13	:	Digit 1 red
 * Sector 14..15	:	Digit 2 red
 * Sector 16..17	:	Digit 3 red
 * Sector 18..19	:	Digit 4 red
 * Sector 1a..1b	:	Digit 5 red
 * Sector 1c..1d	:	Digit 6 red
 * Sector 1e..1f	:	Digit 7 red
 * Sector 20..21	:	Digit 8 red
 * Sector 22..23	:	Digit 9 red
 * Sector 24..2f	:	Unused
 * Sector 30..31	:	Digit 0 green
 * Sector 32..33	:	Digit 1 green
 * Sector 34..35	:	Digit 2 green
 * Sector 36..37	:	Digit 3 green
 * Sector 38..39	:	Digit 4 green
 * Sector 3a..3b	:	Digit 5 green
 * Sector 3c..3d	:	Digit 6 green
 * Sector 3e..3f	:	Digit 7 green
 * Sector 40..41	:	Digit 8 green
 * Sector 42..43	:	Digit 9 green
 * Sector 44..4f	:	Unused
 * Sector 50..51	:	Digit 0 yellow
 * Sector 52..53	:	Digit 1 yellow
 * Sector 54..55	:	Digit 2 yellow
 * Sector 56..57	:	Digit 3 yellow
 * Sector 58..59	:	Digit 4 yellow
 * Sector 5a..5b	:	Digit 5 yellow
 * Sector 5c..5d	:	Digit 6 yellow
 * Sector 5e..5f	:	Digit 7 yellow
 * Sector 60..61	:	Digit 8 yellow
 * Sector 62..63	:	Digit 9 yellow
 * Sector 64..6f	:	Unused
 */


void StoreSettingsInFlash(void)
{
	flash_EraseSector(HEADER_SECTOR);
	flash_WriteBytes((uint8_t *)&SystemParameters ,flash_SectorToAddress(HEADER_SECTOR),sizeof(SystemParameters));
}

void LoadSettingsFromFlash(void)
{
	flash_ReadBytes((uint8_t *)&SystemParameters,flash_SectorToAddress(HEADER_SECTOR),sizeof(SystemParameters));
}

uint32_t	FlashIs256	= 0;
#define BOOT_Y_DELTA	20
uint32_t SetupFlash(void)
{
uint32_t	FlashID,ypos=0,i;
char		message[32];

	ILI9341_WriteString(0, ypos, "SintMate booting ...", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	ypos += BOOT_Y_DELTA;
	ILI9341_WriteString(0, ypos, "Checking FLASH ...", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);

	for(i=0;i<3;i++)
	{
		HAL_Delay(10);
		FlashID = flash_ReadID();
	}
	if (( FlashID & 0xff ) == F128 )	/* 128 MBits */
	{
		SystemParameters.flash_capacity = F128;
		ILI9341_WriteString(100, ypos, "128 MBits", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	}
	else if (( FlashID & 0xff ) == F256 )	/* 256 MBits */
	{
		SystemParameters.flash_capacity = F256;
		ILI9341_WriteString(130, ypos, "256 MBits", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	}
	else
	{
		ILI9341_WriteString(100, ypos, "Failed!!", Font_7x10, ILI9341_RED, ILI9341_BLACK);
		HAL_Delay(1000);
		return -1;
	}
	HAL_Delay(10);
	ypos += BOOT_Y_DELTA;
	ILI9341_WriteString(0, ypos, "Loading params ...", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	LoadSettingsFromFlash();
	if ( strncmp(SystemParameters.Header,SintMateNAME,strlen(SintMateNAME) ) != 0 )
	{
		ILI9341_WriteString(100, ypos, "Invalid", Font_7x10, ILI9341_RED, ILI9341_BLACK);
		ypos += BOOT_Y_DELTA;
		sprintf(message,"Flash value : %s",SystemParameters.Header);
		ILI9341_WriteString(0, ypos, message, Font_7x10, ILI9341_RED, ILI9341_BLACK);
		ypos += BOOT_Y_DELTA;
		ILI9341_WriteString(0, ypos, "Setting defaults ...", Font_7x10, ILI9341_RED, ILI9341_BLACK);
		HAL_Delay(100);
		SintMate_SystemSetDefaults();
		StoreSettingsInFlash();
		LoadSettingsFromFlash();
	}
	ILI9341_WriteString(100, ypos, "Done", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	ypos += BOOT_Y_DELTA;
	ILI9341_WriteString(0, ypos, "Starting ...", Font_7x10, ILI9341_BLUE, ILI9341_BLACK);
	HAL_Delay(100);
	ILI9341_FillScreen(ILI9341_BLACK);
	return SystemParameters.flash_capacity;
}





