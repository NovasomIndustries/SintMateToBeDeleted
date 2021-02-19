/*
 * SintMateTouchProcess.h
 *
 *  Created on: Feb 10, 2021
 *      Author: fil
 */

#ifndef INC_SINTMATE_SINTMATETOUCHPROCESS_H_
#define INC_SINTMATE_SINTMATETOUCHPROCESS_H_

#define TOUCH_X0AREA_PLAYPAUSE		PLAYPAUSE_BUTTON_POSX
#define TOUCH_X1AREA_PLAYPAUSE		PLAYPAUSE_BUTTON_POSX+BUTTONS_WIDTH
#define TOUCH_Y0AREA_PLAYPAUSE		ILI9341_HEIGHT-(PLAYPAUSE_BUTTON_POSY+BUTTONS_HEIGHT)
#define TOUCH_Y1AREA_PLAYPAUSE		ILI9341_HEIGHT-PLAYPAUSE_BUTTON_POSY

#define TOUCH_X0AREA_INCREASE		INCREASE_BUTTON_POSX
#define TOUCH_X1AREA_INCREASE		INCREASE_BUTTON_POSX+BUTTONS_WIDTH
#define TOUCH_Y0AREA_INCREASE		ILI9341_HEIGHT-(INCREASE_BUTTON_POSY+BUTTONS_HEIGHT)
#define TOUCH_Y1AREA_INCREASE		ILI9341_HEIGHT-INCREASE_BUTTON_POSY

#define TOUCH_X0AREA_DECREASE		DECREASE_BUTTON_POSX
#define TOUCH_X1AREA_DECREASE		DECREASE_BUTTON_POSX+BUTTONS_WIDTH
#define TOUCH_Y0AREA_DECREASE		ILI9341_HEIGHT-(DECREASE_BUTTON_POSY+BUTTONS_HEIGHT)
#define TOUCH_Y1AREA_DECREASE		ILI9341_HEIGHT-DECREASE_BUTTON_POSY

#define TOUCH_X0AREA_SETTINGS		SETTINGS_BUTTON_POSX
#define TOUCH_X1AREA_SETTINGS		SETTINGS_BUTTON_POSX+ICONS_WIDTH
#define TOUCH_Y0AREA_SETTINGS		ILI9341_HEIGHT-(SETTINGS_BUTTON_POSY+ICONS_HEIGHT)
#define TOUCH_Y1AREA_SETTINGS		ILI9341_HEIGHT-SETTINGS_BUTTON_POSY

#define TOUCH_X0AREA_HOME			HOME_BUTTON_POSX
#define TOUCH_X1AREA_HOME			HOME_BUTTON_POSX+ICONS_WIDTH
#define TOUCH_Y0AREA_HOME			ILI9341_HEIGHT-(HOME_BUTTON_POSY+ICONS_HEIGHT)
#define TOUCH_Y1AREA_HOME			ILI9341_HEIGHT-HOME_BUTTON_POSY

#define TOUCH_X0AREA_BACK			BACK_BUTTON_POSX
#define TOUCH_X1AREA_BACK			BACK_BUTTON_POSX+BACK_WIDTH
#define TOUCH_Y0AREA_BACK			ILI9341_HEIGHT-(BACK_BUTTON_POSY+BACK_HEIGHT)
#define TOUCH_Y1AREA_BACK			ILI9341_HEIGHT-BACK_BUTTON_POSY


extern	uint32_t SintMateTouchProcess(void);

#endif /* INC_SINTMATE_SINTMATETOUCHPROCESS_H_ */
