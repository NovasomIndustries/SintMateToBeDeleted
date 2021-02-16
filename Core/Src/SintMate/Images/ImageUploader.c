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
uint32_t	usb_rxed_byte_count , usb_byte_count, usb_rx_index , usb_bytes_to_receive,image_is_9;

void ReceiveUSBPacket(void)
{
uint32_t	i;

	if ( SystemVar.usb_image_number > 9 )
	{
		SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
		SystemVar.usb_rx_index  = 0;
		return;
	}

	for(i=0;i<SystemVar.usb_rxed_byte_count;i+=2)
	{
		image_buffer[usb_rx_index] =  ((SystemVar.usb_rxed_packet[i] & 0x0f) << 4)|(SystemVar.usb_rxed_packet[i+1] & 0x0f);
		usb_rx_index ++;
		if ( usb_rx_index > usb_bytes_to_receive-1)
		{

			if ( SystemVar.usb_image_number == 9 )
				image_is_9 = 1;

			usb_rx_index = 0;
			bzero(Green[SystemVar.usb_image_number],DIGIT_SIZE);
			for(i=0;i<usb_bytes_to_receive;i+=2)
			{
				Green[SystemVar.usb_image_number][usb_rx_index] = (image_buffer[i]<<8) | image_buffer[i+1];
				usb_rx_index++;
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

uint32_t ParseUSBPacket(void)
{
uint32_t	pnum;
int			a , b;

	pnum = sscanf((char *)SystemVar.usb_packet,"IMAGE=Green%d SIZE=%d",&a,&b);
	SystemVar.usb_image_number = a;
	SystemVar.usb_byte_count = b;
	if ( SystemVar.usb_image_number > 9 )
	{
		sprintf((char *)usb_uploader_tx_buf,"NOK image_num %d\n",SystemVar.usb_image_number);
		CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));
		SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
		return 1;
	}
	if ( pnum == 2 )
	{
		bzero(usb_uploader_tx_buf,64);
		sprintf((char *)usb_uploader_tx_buf,"%d %d OK",(int )SystemVar.usb_image_number,(int )SystemVar.usb_byte_count);
		CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));

		SystemVar.usb_rx_index  = 0;
		SystemVar.usb_pkt_found = USB_RECEIVING_PACKET;
		usb_rxed_byte_count = usb_byte_count = usb_rx_index = 0;
		usb_bytes_to_receive = SystemVar.usb_byte_count/2;
		return 0;
	}
	else
	{
		sprintf((char *)usb_uploader_tx_buf,"NOK pnum %d\n",(int )pnum);
		CDC_Transmit_FS(usb_uploader_tx_buf,strlen((char *)usb_uploader_tx_buf));
		SystemVar.usb_pkt_found = USB_WAIT_FOR_HEADER;
		return 1;
	}
}

uint32_t AnalyzeUSBHeader(void)
{
uint16_t	i;
	for(i=0;i<SystemVar.usb_rxed_byte_count;i++)
	{
		if ( SystemVar.usb_rxed_packet[i] == '<' )
		{
			SystemVar.usb_byte_count = 0;
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
	case	USB_WAIT_FOR_HEADER 	: if ( AnalyzeUSBHeader() == 0 )
										{
											ParseUSBPacket();
										}
										break;
	case	USB_RECEIVING_PACKET 	: ReceiveUSBPacket(); break;
	default 						: default_case();break;
	}
	return SystemVar.usb_pkt_found;
}



