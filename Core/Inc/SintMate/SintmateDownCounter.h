/*
 * SintmateDownCounter.h
 *
 *  Created on: Feb 9, 2021
 *      Author: fil
 */

#ifndef INC_SINTMATE_SINTMATEDOWNCOUNTER_H_
#define INC_SINTMATE_SINTMATEDOWNCOUNTER_H_

#define	DOWNCOUNTER_DIGITSPACE	1
#define	DOWNCOUNTER_POSX		(((ILI9341_WIDTH-DIGIT_WIDTH*3)/2)+(2*DOWNCOUNTER_DIGITSPACE))
#define	DOWNCOUNTER_100_POSX	DOWNCOUNTER_POSX
#define	DOWNCOUNTER_10_POSX		(DOWNCOUNTER_POSX+DOWNCOUNTER_DIGITSPACE+DIGIT_WIDTH)
#define	DOWNCOUNTER_1_POSX		(DOWNCOUNTER_POSX+DOWNCOUNTER_DIGITSPACE+DIGIT_WIDTH*2)
#define	DOWNCOUNTER_POSY		((ILI9341_HEIGHT-DIGIT_HEIGHT)/2)

extern	void Tim100MSec_callback(void);
extern	void InitCounter(void);
extern	void SetCounter(uint32_t value, uint32_t color);
extern	void IncrementCounter(void);
extern	void DecrementCounter(void);


#endif /* INC_SINTMATE_SINTMATEDOWNCOUNTER_H_ */
