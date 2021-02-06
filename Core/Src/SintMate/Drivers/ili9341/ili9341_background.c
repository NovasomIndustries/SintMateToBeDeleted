/*
 * ili9341_background.c
 *
 *  Created on: Feb 5, 2021
 *      Author: fil
 */

#include "main.h"

uint8_t	image_buf[ILI9341_WIDTH*ILI9341_HEIGHT*2];

void tempwritebkg(uint16_t background_index)
{
uint32_t	i,sector,number_of_sectors;
uint8_t	*buf_ptr = 	image_buf;
	sector = background_index+BACKGROUND1_SECTOR;
	number_of_sectors = (ILI9341_WIDTH*ILI9341_HEIGHT*2)/SECTOR_SIZE;
	for(i=0;i<ILI9341_WIDTH*ILI9341_HEIGHT*2;i++)
		image_buf[i] = i;

	for(i=0;i<number_of_sectors;i++)
	{
		flash_WriteBytes(buf_ptr,flash_SectorToAddress(i+sector),SECTOR_SIZE);
		buf_ptr += SECTOR_SIZE;
	}
}
extern	uint8_t GIMP_IMAGE_pixel_data[240 * 320 * 2 + 1];

void LoadBackgroundImage(uint16_t background_index)
{
uint32_t	i,sector,number_of_sectors;
uint8_t	*buf_ptr = 	GIMP_IMAGE_pixel_data;
	sector = background_index+BACKGROUND1_SECTOR;
	number_of_sectors = (ILI9341_WIDTH*ILI9341_HEIGHT*2)/SECTOR_SIZE;
	for(i=0;i<number_of_sectors;i++)
	{
		flash_ReadBytes(buf_ptr,flash_SectorToAddress(i+sector),SECTOR_SIZE);
		buf_ptr += SECTOR_SIZE;
	}
	ILI9341_DrawImage(0, 0, ILI9341_WIDTH-1, ILI9341_HEIGHT-1, (uint16_t *) GIMP_IMAGE_pixel_data);
}
