/*
 * ImageUploader.c
 *
 *  Created on: Feb 15, 2021
 *      Author: fil
 */

#include "main.h"

uint8_t		usb_uploader_tx_buf[64];
extern	uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);
uint8_t		image_buffer[32768]; // the biggest one
uint32_t	usb_rxed_byte_count , usb_byte_count, usb_rx_index , usb_bytes_to_receive,restart_flag , stored_image;

void ReceiveUSBPacket(void)
{
uint32_t	i;

	for(i=0;i<SystemVar.usb_rxed_byte_count;i+=2)
	{
		if ( i > 4 )
		{
			restart_flag = ((SystemVar.usb_rxed_packet[i]<<24 ) | (SystemVar.usb_rxed_packet[i-1] << 16 ) | (SystemVar.usb_rxed_packet[i-2] << 8 ) | (SystemVar.usb_rxed_packet[i-3] << 0 ) );
			if ( restart_flag == 0xADBEEFDE)
			{
				SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
				SystemVar.usb_rx_index  = 0;
				return;
			}
		}

		image_buffer[usb_rx_index] =  ((SystemVar.usb_rxed_packet[i] & 0x0f) << 4)|(SystemVar.usb_rxed_packet[i+1] & 0x0f);
		usb_rx_index ++;
		if ( usb_rx_index > usb_bytes_to_receive-1)
		{
			usb_rx_index = 0;
			if ( strcmp ( (char *)SystemVar.usb_image_name , "green") == 0 )
			{
				bzero(Green[SystemVar.usb_image_number],DIGIT_SIZE);
				for(i=0;i<usb_bytes_to_receive;i+=2)
				{
					Green[SystemVar.usb_image_number][usb_rx_index] = (image_buffer[i]<<8) | image_buffer[i+1];
					usb_rx_index++;
				}
			}
			if ( strcmp ( (char *)SystemVar.usb_image_name , "yellow") == 0 )
			{
				bzero(Yellow[SystemVar.usb_image_number],DIGIT_SIZE);
				for(i=0;i<usb_bytes_to_receive;i+=2)
				{
					Yellow[SystemVar.usb_image_number][usb_rx_index] = (image_buffer[i]<<8) | image_buffer[i+1];
					usb_rx_index++;
				}
			}
			if ( strcmp ( (char *)SystemVar.usb_image_name , "red") == 0 )
			{
				bzero(Red[SystemVar.usb_image_number],DIGIT_SIZE);
				for(i=0;i<usb_bytes_to_receive;i+=2)
				{
					Red[SystemVar.usb_image_number][usb_rx_index] = (image_buffer[i]<<8) | image_buffer[i+1];
					usb_rx_index++;
				}
			}
			SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
			SystemVar.usb_rx_index  = 0;

			bzero(usb_uploader_tx_buf,64);
			sprintf((char *)usb_uploader_tx_buf,"Finished %d %d",(int )SystemVar.usb_image_number,(int )usb_bytes_to_receive);
			CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));

			return;
		}
	}
}

static void store_image(void)
{
uint32_t	i,j,base;
	if ( strcmp ( (char *)SystemVar.usb_image_name , "green") == 0 )
		base = DIGITGREEN_BASE;
	if ( strcmp ( (char *)SystemVar.usb_image_name , "red") == 0 )
		base = DIGITRED_BASE;
	if ( strcmp ( (char *)SystemVar.usb_image_name , "yellow") == 0 )
		base = DIGITYELLOW_BASE;
	for(j=0;j<32;j++)
	{
		flash_EraseSector(base+j);
	}
/*
	bzero(usb_uploader_tx_buf,64);
	sprintf((char *)usb_uploader_tx_buf,"ERASED %s\n",SystemVar.usb_image_name);
	CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));
*/

	for(i=0;i<10;i++)
	{
		if ( strcmp ( (char *)SystemVar.usb_image_name , "green") == 0 )
		{
			flash_WriteBytes((uint8_t *)Green[i] ,flash_SectorToAddress(i*2+DIGITGREEN_BASE),DIGIT_SIZE*2);
		}
		if ( strcmp ( (char *)SystemVar.usb_image_name , "red") == 0 )
		{
			flash_WriteBytes((uint8_t *)Red[i] ,flash_SectorToAddress(i*2+DIGITRED_BASE),DIGIT_SIZE*2);
		}
		if ( strcmp ( (char *)SystemVar.usb_image_name , "yellow") == 0 )
		{
			flash_WriteBytes((uint8_t *)Yellow[i] ,flash_SectorToAddress(i*2+DIGITYELLOW_BASE),DIGIT_SIZE*2);
		}
	}


	bzero(usb_uploader_tx_buf,64);
	sprintf((char *)usb_uploader_tx_buf,"STORED %s\n",SystemVar.usb_image_name);
	CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));


	SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
}

uint32_t ParseUSBPacket(void)
{
uint32_t	pnum;
int			a , b;

	bzero(SystemVar.usb_image_name,sizeof(SystemVar.usb_image_name));
	pnum = sscanf((char *)SystemVar.usb_packet,"STORE %s",SystemVar.usb_image_name);
	if ( pnum == 1 )
	{
		store_image();
	}
	pnum = sscanf((char *)SystemVar.usb_packet,"IMAGE %s %d SIZE %d",SystemVar.usb_image_name,&a,&b);
	if ( pnum == 3 )
	{
		SystemVar.usb_image_number = a;
		SystemVar.usb_byte_count = b;
		if ( SystemVar.usb_image_number > 9 )
		{
			bzero(usb_uploader_tx_buf,64);
			sprintf((char *)usb_uploader_tx_buf,"NOK image_num %d\n",SystemVar.usb_image_number);
			CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));
			SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
			return 1;
		}
		if (( strcmp ( (char *)SystemVar.usb_image_name , "green") != 0 ) &&( strcmp ( (char *)SystemVar.usb_image_name , "yellow") != 0 ) &&( strcmp ( (char *)SystemVar.usb_image_name , "red") != 0 ) )
		{
			bzero(usb_uploader_tx_buf,64);
			sprintf((char *)usb_uploader_tx_buf,"NOK image_color %s\n",SystemVar.usb_image_name);
			CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));
			SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
			return 1;
		}
		bzero(usb_uploader_tx_buf,64);
		sprintf((char *)usb_uploader_tx_buf,"%d %d OK",(int )SystemVar.usb_image_number,(int )SystemVar.usb_byte_count);
		CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));

		SystemVar.usb_rx_index  = 0;
		SystemVar.usb_pkt_found = USB_RECEIVING_PACKET;
		usb_rxed_byte_count = usb_byte_count = usb_rx_index = 0;
		usb_bytes_to_receive = SystemVar.usb_byte_count/2;
		return 0;
	}

	bzero(usb_uploader_tx_buf,64);
	sprintf((char *)usb_uploader_tx_buf,"NOK pnum %d\n",(int )pnum);
	CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));
	SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
	return 1;
}

uint32_t AnalyzeUSBHeader(void)
{
uint16_t	i;
	for(i=0;i<SystemVar.usb_rxed_byte_count;i++)
	{
		if ( SystemVar.usb_rxed_packet[i] == '<' )
		{
			bzero(SystemVar.usb_packet,USB_BUFLEN);
			SystemVar.usb_byte_count = SystemVar.usb_rx_index = 0;
			SystemVar.usb_do_cp=1;
		}
		else
		{
			if ( SystemVar.usb_do_cp == 1 )
			{
				if ( SystemVar.usb_rxed_packet[i] == '>' )
				{
					SystemVar.usb_do_cp=0;
					return 0;
				}
				else
				{
					SystemVar.usb_packet[SystemVar.usb_rx_index] = SystemVar.usb_rxed_packet[i];
					SystemVar.usb_byte_count ++;
					SystemVar.usb_rx_index++;
					if ( SystemVar.usb_rx_index >= USB_BUFLEN)
						SystemVar.usb_rx_index = 0;
				}
			}
		}
	}
	return 1;
}

void default_case(void)
{
	SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
	SystemVar.usb_rx_index  = 0;
}

uint32_t USB_ImageUploader(void)
{
	switch ( SystemVar.usb_pkt_found )
	{
	case	USB_WAIT_FOR_HEADER 	:   if ( AnalyzeUSBHeader() == 0 )
										{
											ParseUSBPacket();
										}
										break;
	case	USB_RECEIVING_PACKET 	: ReceiveUSBPacket(); break;
	default 						: default_case();break;
	}
	return SystemVar.usb_pkt_found;
}



