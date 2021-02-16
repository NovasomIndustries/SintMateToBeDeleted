#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include "ImageUploader.h"


char            tx_buf[BUFSIZE];
char            rx_buf[BUFSIZE];
char            file_in[128];

extern  unsigned short  image[];
extern  unsigned char   ascii_image[];

int main(void)
{
int serial_port,size_in_bytes,i;
    serial_port = serial_open(SERIAL_DEVICE);
    for(i=0;i<10;i++)
    {
        sprintf(file_in,"/Devel/Stm32Sw/SintMate/Core/Src/SintMate/SrcImages/D%dyellow.bmp",i);
        size_in_bytes = read_and_convert(file_in);
        sprintf(tx_buf,"<IMAGE=Green%d SIZE=%d>",i,size_in_bytes);
        printf("%s\n",tx_buf);
        if ( serial_tx_rx(serial_port,tx_buf,size_in_bytes,rx_buf) != -1 )
        {
            serial_send_file(serial_port,(char *)ascii_image,size_in_bytes,rx_buf);
            //printf("Image Green%d sent ( %d bytes )\n", i,serial_send_file(serial_port,(char *)image,size_in_bytes,rx_buf));
        }
        else
        {
            printf("Error sending Image\n");
            break;
        }
    }

    serial_close(serial_port);
    return 0; // success
}
