/*
 * DigitsBitmap.c
 *
 *  Created on: Feb 8, 2021
 *      Author: fil
 */

#include "main.h"
#include "Digits.h"

#define	DIGITRED_IDX		0
#define	DIGITGREEN_IDX		1
#define	DIGITYELLOW_IDX		2
#define	DIGIT_TYPESNUMBER	3


#ifdef	DIGIT_GREEN
DIGIT_BUFFERS		__attribute__ ((aligned (16)))	  uint16_t Green[10][DIGIT_SIZE];
//__attribute__	((aligned (16)))	uint16_t Green[10][DIGIT_SIZE];
#endif
#ifdef	DIGIT_RED
//__attribute__ ((aligned (16)))	uint16_t Red[10][DIGIT_SIZE];
DIGIT_BUFFERS		__attribute__ ((aligned (16)))	uint16_t Red[10][DIGIT_SIZE];
#endif
#ifdef	DIGIT_YELLOW
//__attribute__ ((aligned (16)))	uint16_t Yellow[10][DIGIT_SIZE];
DIGIT_BUFFERS		__attribute__ ((aligned (16)))	uint16_t Yellow[10][DIGIT_SIZE];
#endif
DIGIT_BUFFERS 	__attribute__ ((aligned (16)))	uint16_t DigitOFF[DIGIT_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t play[BUTTONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t stop[BUTTONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t SintmateLogo[LOGO_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Increase[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Increase_disabled[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Decrease[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Decrease_disabled[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Settings[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Settings_disabled[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Home[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Home_disabled[ICONS_SIZE];

void GetDigitsFromFlash(void)
{
uint32_t i;

	for(i=0;i<10;i++)
	{
		flash_ReadBytes((uint8_t*)&Red[i][0], flash_SectorToAddress(i*2+DIGITRED_BASE), DIGIT_SIZE*2);
		flash_ReadBytes((uint8_t*)&Green[i][0], flash_SectorToAddress(i*2+DIGITGREEN_BASE), DIGIT_SIZE*2);
		flash_ReadBytes((uint8_t*)&Yellow[i][0], flash_SectorToAddress(i*2+DIGITYELLOW_BASE), DIGIT_SIZE*2);
	}
	flash_ReadBytes((uint8_t*)&DigitOFF[0], 			flash_SectorToAddress(DIGITOFF_BASE), DIGIT_SIZE*2);
	flash_ReadBytes((uint8_t*)&SintmateLogo[0], 		flash_SectorToAddress(LOGO_BASE), LOGO_SIZE*2);
	flash_ReadBytes((uint8_t*)&Increase[0], 			flash_SectorToAddress(INCREASE_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Increase_disabled[0], 	flash_SectorToAddress(INCREASE_DISABLED_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Decrease[0], 			flash_SectorToAddress(DECREASE_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Decrease_disabled[0], 	flash_SectorToAddress(DECREASE_DISABLED_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Settings[0], 			flash_SectorToAddress(SETTINGS_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Settings_disabled[0], 	flash_SectorToAddress(SETTINGS_DISABLED_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Home[0], 				flash_SectorToAddress(HOME_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&Home_disabled[0], 		flash_SectorToAddress(HOME_DISABLED_BASE), ICONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&play[0], 				flash_SectorToAddress(PLAY_BASE), BUTTONS_SIZE*2);
	flash_ReadBytes((uint8_t*)&stop[0], 				flash_SectorToAddress(STOP_BASE), BUTTONS_SIZE*2);
}

