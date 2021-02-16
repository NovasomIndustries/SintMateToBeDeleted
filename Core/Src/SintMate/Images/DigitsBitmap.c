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
//DIGIT_BUFFERS		__attribute__ ((aligned (16)))	  uint16_t Green[10][DIGIT_SIZE];
__attribute__	((aligned (16)))	uint16_t Green[10][DIGIT_SIZE];
#endif
#ifdef	DIGIT_RED
//__attribute__ ((aligned (16)))	uint16_t Red[10][DIGIT_SIZE];
DIGIT_BUFFERS		__attribute__ ((aligned (16)))	uint16_t Red[10][DIGIT_SIZE];
#endif
#ifdef	DIGIT_YELLOW
__attribute__ ((aligned (16)))	uint16_t Yellow[10][DIGIT_SIZE];
//DIGIT_BUFFERS		__attribute__ ((aligned (16)))	uint16_t Yellow[10][DIGIT_SIZE];
#endif
DIGIT_BUFFERS 	__attribute__ ((aligned (16)))	uint16_t DigitOFF[DIGIT_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t StartButton[BUTTONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t StopButton[BUTTONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t SintmateLogo[LOGO_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Increase[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Increase_disabled[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Decrease[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Decrease_disabled[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Settings[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Settings_disabled[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Home[ICONS_SIZE];
DIGIT_BUFFERS	__attribute__ ((aligned (16)))	uint16_t Home_disabled[ICONS_SIZE];

//#define	WRITE	1

#ifdef	WRITE

//#define	RED_ENABLE		1
//#define	GREEN_ENABLE		1
//#define	YELLOW_ENABLE	1
#define	OFF_ENABLE			1
#define	LOGO_ENABLE			1
#define	BUTTONS_ENABLE			1


#ifdef	RED_ENABLE
uint16_t	*red_ptr_array[10] =
{
		D0red,
		D1red,
		D2red,
		D3red,
		D4red,
		D5red,
		D6red,
		D7red,
		D8red,
		D9red
};
#endif
#ifdef	GREEN_ENABLE
uint16_t	*green_ptr_array[10] =
{
		D0green,
		D1green,
		D2green,
		D3green,
		D4green,
		D5green,
		D6green,
		D7green,
		D8green,
		D9green
};
#endif
#ifdef	YELLOW_ENABLE
uint16_t	*yellow_ptr_array[10] =
{
		D0yellow,
		D1yellow,
		D2yellow,
		D3yellow,
		D4yellow,
		D5yellow,
		D6yellow,
		D7yellow,
		D8yellow,
		D9yellow
};
#endif

extern	uint16_t SintMateLogo[];

void flash_erase_sectors(void)
{
uint32_t 	i;

#ifdef	OFF_ENABLE
	flash_EraseSector(DIGITOFF_BASE);
	flash_EraseSector(DIGITOFF_BASE+1);
#endif

#ifdef	LOGO_ENABLE
	for(i=0;i<((LOGO_SIZE*2)/4096)+1;i++)
		flash_EraseSector(i+LOGO_BASE);
#endif
	for(i=0;i<32;i++)
	{
#ifdef	RED_ENABLE
		flash_EraseSector(DIGITRED_BASE+i);
#endif
#ifdef	GREEN_ENABLE
		flash_EraseSector(DIGITGREEN_BASE+i);
#endif
#ifdef	YELLOW_ENABLE
		flash_EraseSector(DIGITYELLOW_BASE+i);
#endif
	}
#ifdef	BUTTONS_ENABLE
	flash_EraseSector(INCREASE_BASE);
	flash_EraseSector(INCREASE_BASE+1);
	flash_EraseSector(INCREASE_DISABLED_BASE);
	flash_EraseSector(INCREASE_DISABLED_BASE+1);
	flash_EraseSector(DECREASE_BASE);
	flash_EraseSector(DECREASE_BASE+1);
	flash_EraseSector(DECREASE_DISABLED_BASE);
	flash_EraseSector(DECREASE_DISABLED_BASE+1);
	flash_EraseSector(SETTINGS_BASE);
	flash_EraseSector(SETTINGS_BASE+1);
	flash_EraseSector(SETTINGS_DISABLED_BASE);
	flash_EraseSector(SETTINGS_DISABLED_BASE+1);
	flash_EraseSector(HOME_BASE);
	flash_EraseSector(HOME_BASE+1);
	flash_EraseSector(HOME_DISABLED_BASE);
	flash_EraseSector(HOME_DISABLED_BASE+1);
#endif
	HAL_Delay(5);
}

void StoreDigitsInFlash(void)
{
uint32_t 	i;

	flash_erase_sectors();
	for(i=0;i<10;i++)
	{
#ifdef	RED_ENABLE
		flash_WriteBytes((uint8_t *)red_ptr_array[i] ,flash_SectorToAddress(i*2+DIGITRED_BASE),DIGIT_SIZE*2);
#endif
#ifdef	GREEN_ENABLE
		flash_WriteBytes((uint8_t *)green_ptr_array[i] ,flash_SectorToAddress(i*2+DIGITGREEN_BASE),DIGIT_SIZE*2);
#endif
#ifdef	YELLOW_ENABLE
		flash_WriteBytes((uint8_t *)yellow_ptr_array[i] ,flash_SectorToAddress(i*2+DIGITYELLOW_BASE),DIGIT_SIZE*2);
#endif
	}
#ifdef	RED_ENABLE
		flash_WriteBytes((uint8_t *)red_ptr_array[0] ,flash_SectorToAddress(DIGITRED_BASE),DIGIT_SIZE*2);
#endif
#ifdef	GREEN_ENABLE
		flash_WriteBytes((uint8_t *)green_ptr_array[0] ,flash_SectorToAddress(DIGITGREEN_BASE),DIGIT_SIZE*2);
#endif
#ifdef	YELLOW_ENABLE
		flash_WriteBytes((uint8_t *)yellow_ptr_array[0] ,flash_SectorToAddress(DIGITYELLOW_BASE),DIGIT_SIZE*2);
#endif
#ifdef	OFF_ENABLE
	flash_WriteBytes((uint8_t *)RedOFF ,flash_SectorToAddress(DIGITOFF_BASE),DIGIT_SIZE*2);
#endif
#ifdef	LOGO_ENABLE
	flash_WriteBytes((uint8_t *)SintMateLogo ,flash_SectorToAddress(LOGO_BASE),LOGO_SIZE*2);
#endif
#ifdef	BUTTONS_ENABLE
	flash_WriteBytes((uint8_t *)increase 			,flash_SectorToAddress(INCREASE_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)increase_disabled 	,flash_SectorToAddress(INCREASE_DISABLED_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)decrease 			,flash_SectorToAddress(DECREASE_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)decrease_disabled 	,flash_SectorToAddress(DECREASE_DISABLED_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)settings 			,flash_SectorToAddress(SETTINGS_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)settings_disabled 	,flash_SectorToAddress(SETTINGS_DISABLED_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)home 				,flash_SectorToAddress(HOME_BASE),ICONS_SIZE*2);
	flash_WriteBytes((uint8_t *)home_disabled 		,flash_SectorToAddress(HOME_DISABLED_BASE),ICONS_SIZE*2);
#endif
}
#endif


void GetDigitsFromFlash(void)
{
uint32_t i;

	for(i=0;i<10;i++)
	{
	#ifdef	DIGIT_RED
		flash_ReadBytes((uint8_t*)&Red[i][0], flash_SectorToAddress(i*2+DIGITRED_BASE), DIGIT_SIZE*2);
	#endif
	#ifdef	DIGIT_GREEN
		flash_ReadBytes((uint8_t*)&Green[i][0], flash_SectorToAddress(i*2+DIGITGREEN_BASE), DIGIT_SIZE*2);
	#endif
	#ifdef	DIGIT_YELLOW
		flash_ReadBytes((uint8_t*)&Yellow[i][0], flash_SectorToAddress(i*2+DIGITYELLOW_BASE), DIGIT_SIZE*2);
	#endif
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
}


