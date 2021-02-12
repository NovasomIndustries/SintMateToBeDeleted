/*
 * flash_manager.h
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#ifndef INC_SINTMATE_FLASH_MANAGER_H_
#define INC_SINTMATE_FLASH_MANAGER_H_

#include "SpiFlash.h"

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


#define	HEADER_SECTOR			0
#define	PROGRAM_SECTOR			1
#define	DUMMY_PAGE0				8
#define	DUMMY_PAGE1				9
#define	DUMMY_PAGE2				0x0a
#define	DUMMY_PAGE3				0x0b
#define	DIGITSECTORPERCOLOR		32
#define	DIGITRED_BASE			0x10
#define	DIGITGREEN_BASE			0x30
#define	DIGITYELLOW_BASE		0x50
#define	DIGITOFF_BASE			0x70
#define	LOGO_BASE				0x80


extern	uint32_t SetupFlash(void);
extern	void StoreSettingsInFlash(void);
extern	void LoadSettingsFromFlash(void);

#endif /* INC_SINTMATE_FLASH_MANAGER_H_ */
