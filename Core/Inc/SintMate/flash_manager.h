/*
 * flash_manager.h
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#ifndef INC_SINTMATE_FLASH_MANAGER_H_
#define INC_SINTMATE_FLASH_MANAGER_H_

#include "SpiFlash.h"

#define	HEADER_SECTOR			0
#define	DIGITOFF_BASE			1
#define	LOGO_BASE				8
#define	DIGITRED_BASE			0x10
#define	DIGITGREEN_BASE			0x30
#define	DIGITYELLOW_BASE		0x50
#define	INCREASE_BASE			0x60
#define	INCREASE_DISABLED_BASE	0x62
#define	DECREASE_BASE			0x64
#define	DECREASE_DISABLED_BASE	0x66
#define	SETTINGS_BASE			0x68
#define	SETTINGS_DISABLED_BASE	0x6a
#define	HOME_BASE				0x6c
#define	HOME_DISABLED_BASE		0x6e

#define	DIGITSECTORPERCOLOR		32


extern	uint32_t SetupFlash(void);
extern	void StoreSettingsInFlash(void);
extern	void LoadSettingsFromFlash(void);

#endif /* INC_SINTMATE_FLASH_MANAGER_H_ */
