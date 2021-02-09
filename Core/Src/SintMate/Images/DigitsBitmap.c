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

uint16_t Red[10][DIGIT_SIZE];
uint16_t Green[10][DIGIT_SIZE];
uint16_t Yellow[10][DIGIT_SIZE];

//#define	WRITE	1

#ifdef	WRITE
uint16_t	*ptr_array[10] =
{
		/*
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
		*/
		/*
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
		*/
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

void StoreDigitsInFlash(void)
{
#ifdef	WRITE
uint32_t 	i,numsect2erase;

	numsect2erase = DIGITSECTORPERCOLOR;
	for(i=0;i<numsect2erase;i++)
		flash_EraseSector(i+DIGITYELLOW_BASE);
	for(i=0;i<10;i++)
		flash_WriteBytes((uint8_t *)ptr_array[i] ,flash_SectorToAddress(i*2+DIGITYELLOW_BASE),DIGIT_SIZE*2);
#endif
}

void GetDigitsFromFlash(void)
{
uint32_t i;

	for(i=0;i<10;i++)
	{
		flash_ReadBytes((uint8_t*)&Red[i][0], flash_SectorToAddress(i*2+DIGITRED_BASE), DIGIT_SIZE*2);
		flash_ReadBytes((uint8_t*)&Green[i][0], flash_SectorToAddress(i*2+DIGITGREEN_BASE), DIGIT_SIZE*2);
		flash_ReadBytes((uint8_t*)&Yellow[i][0], flash_SectorToAddress(i*2+DIGITYELLOW_BASE), DIGIT_SIZE*2);
	}
}

