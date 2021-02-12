/*
 * DigitsBitmap.c
 *
 *  Created on: Feb 8, 2021
 *      Author: fil
 */

#include "main.h"

#define	DIGITRED_IDX		0
#define	DIGITGREEN_IDX		1
#define	DIGITYELLOW_IDX		2
#define	DIGIT_TYPESNUMBER	3

#define	DIGIT_GREEN			1
#define	DIGIT_RED			1
#define	DIGIT_YELLOW		1

#ifdef	DIGIT_GREEN
//DIGIT_BUFFERS		__attribute__ ((aligned (4)))	uint16_t Green[10][DIGIT_SIZE];
__attribute__	((aligned (4)))	uint16_t Green[10][DIGIT_SIZE];
#endif
#ifdef	DIGIT_RED
DIGIT_BUFFERS		__attribute__ ((aligned (4)))	uint16_t Red[10][DIGIT_SIZE];
#endif
#ifdef	DIGIT_YELLOW
DIGIT_BUFFERS		__attribute__ ((aligned (4)))	uint16_t Yellow[10][DIGIT_SIZE];
#endif
__attribute__ ((aligned (4)))	uint16_t DigitOFF[DIGIT_SIZE];
__attribute__ ((aligned (4)))	uint16_t StartButton[BUTTONS_SIZE];
__attribute__ ((aligned (4)))	uint16_t StopButton[BUTTONS_SIZE];
__attribute__ ((aligned (4)))	uint16_t SintmateLogo[LOGO_SIZE];

//#define	WRITE	1

#ifdef	WRITE

//#define	RED_ENABLE		1
//#define	GREEN_ENABLE		1
#define	YELLOW_ENABLE	1
//#define	OFF_ENABLE			1
//#define	LOGO_ENABLE			1


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

	flash_EraseSector(DUMMY_PAGE0);
	flash_EraseSector(DUMMY_PAGE1);
	flash_EraseSector(DUMMY_PAGE2);
	flash_EraseSector(DUMMY_PAGE3);

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
	HAL_Delay(100);
}

void StoreDigitsInFlash(void)
{
uint32_t 	i;

	flash_erase_sectors();

	flash_WriteBytes((uint8_t *)RedOFF ,flash_SectorToAddress(DUMMY_PAGE0),DIGIT_SIZE*2);
	flash_WriteBytes((uint8_t *)RedOFF ,flash_SectorToAddress(DUMMY_PAGE2),DIGIT_SIZE*2);

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

#ifdef	OFF_ENABLE
	flash_WriteBytes((uint8_t *)RedOFF ,flash_SectorToAddress(DIGITOFF_BASE),DIGIT_SIZE*2);
#endif
#ifdef	LOGO_ENABLE
	flash_WriteBytes((uint8_t *)SintMateLogo ,flash_SectorToAddress(LOGO_BASE),LOGO_SIZE*2);
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
	flash_ReadBytes((uint8_t*)&DigitOFF[0], flash_SectorToAddress(DIGITOFF_BASE), DIGIT_SIZE*2);
	flash_ReadBytes((uint8_t*)&SintmateLogo[0], flash_SectorToAddress(LOGO_BASE), LOGO_SIZE*2);
}

