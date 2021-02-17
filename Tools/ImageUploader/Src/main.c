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

void print_error(void)
{
    printf("Arguments -f and -t required\n");
}

int main(int argc, char **argv)
{
int serial_port,size_in_bytes,i;
char   *folder=NULL,*digit=NULL;

    while ((i = getopt (argc, argv, "f:t:")) != -1)
    switch (i)
    {
        case 'f':   folder = optarg;   break;
        case 't':   digit = optarg;   break;
        default:    print_error();return -1;
    }
    if (( folder == NULL ) || (digit == NULL))
    {
        print_error();
        return -1;
    }

    serial_port = serial_open(SERIAL_DEVICE);
    serial_send_restart(serial_port);
    for(i=0;i<10;i++)
    {
        sprintf(file_in,"%s/D%d%s.bmp",folder,i,digit);
        size_in_bytes = read_and_convert(file_in);
        bzero(tx_buf,BUFSIZE);

        sprintf(tx_buf,"<IMAGE %s %d SIZE %d>",digit,i,size_in_bytes);
        printf("%s\n",tx_buf);
        if ( serial_tx_rx(serial_port,tx_buf,size_in_bytes,rx_buf,digit) != -1 )
        {
            serial_send_file(serial_port,(char *)ascii_image,size_in_bytes,rx_buf);
        }
        else
        {
            printf("Error sending Image\n");
            break;
        }
        /*
        for(i=0;i<5;i++)
        {
            printf("%d\n",5-i);
            sleep(1);
        }
        */
        //sleep(1);

    }
    sprintf(tx_buf,"<STORE %s>",digit);
    printf("%s\n",tx_buf);
    serial_send_command(serial_port,tx_buf,digit,rx_buf);

    serial_close(serial_port);
    return 0;
}
