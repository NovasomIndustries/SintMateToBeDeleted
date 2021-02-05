/*
 * flash_manager.c
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#include "main.h"
#include <stdio.h>
#include <string.h>
#include "flash_manager.h"
/*
 * Each sector is 4096 bytes
 * Sector 0 : header + setup data , see SystemParametersTypeDef
 * Sector 1 : program
 * Sector 2 : tab1
 * Sector 3 : tab2
 * Sector 4 ..  : user data
 */
#define	HEADER_SECTOR			0
#define	PROGRAM_SECTOR			1
#define	TAB1_SECTOR				2
#define	TAB2_SECTOR				3
#define	USERDATA_SECTOR			4

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

uint32_t SetupFlash(void)
{
uint32_t	FlashID;
	FlashID = flash_ReadID();
	if (( FlashID & 0xff ) == F128 )	/* 128 MBits */
		SystemParameters.flash_capacity = F128;
	else if (( FlashID & 0xff ) == F256 )	/* 256 MBits */
		SystemParameters.flash_capacity = F256;
	else
		return -1;
	LoadSettingsFromFlash();
	if ( strncmp(SystemParameters.Header,SintMateNAME,10 ) != 0 )
	{
		SintMate_SystemSetDefaults();
		StoreSettingsInFlash();
		LoadSettingsFromFlash();
	}
	return FlashIs256;
}





