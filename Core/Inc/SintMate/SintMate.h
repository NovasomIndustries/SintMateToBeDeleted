/*
 * SintMate.h
 *
 *  Created on: Feb 4, 2021
 *      Author: fil
 */

#ifndef INC_SINTMATE_SYSTEM_H_
#define INC_SINTMATE_SYSTEM_H_

#include "ili9341.h"
#include "ili9341_touch.h"
#include "ili9341_calibrate_touch.h"
#include "fonts.h"
#include "SpiFlash.h"

#define	SintMateNAME		"SintMate  "
#define	SintMateVERSION		"0.0.1"

extern	TIM_HandleTypeDef htim2;
extern	SPI_HandleTypeDef hspi1;
extern	SPI_HandleTypeDef hspi6;

typedef struct _SystemParametersTypeDef
{
	char					Header[16];
	char					Version[16];
	uint32_t 				flash_capacity;
	uint32_t 				touch_is_calibrated;	// 0 not calibrated, !=0 calibrated
	uint32_t 				touch_x_minimum;
	uint32_t 				touch_y_minimum;
	uint32_t 				touch_x_correction;
	uint32_t 				touch_y_correction;
}SystemParametersTypeDef;

typedef struct _SystemVarDef
{
	uint32_t touch_x, touch_y;
}SystemVarDef;

extern	SystemParametersTypeDef	SystemParameters;
extern	SystemVarDef			SystemVar;

void Init_SintMate(void);
void SintMate_SystemSetDefaults(void);


#endif /* INC_SINTMATE_SYSTEM_H_ */
