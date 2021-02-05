/*
 * flash_manager.h
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#ifndef INC_SINTMATE_FLASH_MANAGER_H_
#define INC_SINTMATE_FLASH_MANAGER_H_

#include "SpiFlash.h"

extern	uint32_t SetupFlash(void);
extern	void StoreSettingsInFlash(void);
extern	void LoadSettingsFromFlash(void);

#endif /* INC_SINTMATE_FLASH_MANAGER_H_ */
