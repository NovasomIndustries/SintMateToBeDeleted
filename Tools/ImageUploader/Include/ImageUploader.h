#ifndef IMAGEUPLOADER_H_INCLUDED
#define IMAGEUPLOADER_H_INCLUDED

#define         SERIAL_DEVICE   "/dev/ttyACM0"
#define         BUFSIZE      1024
extern  int serial_open(char *port);
extern  void serial_close(int serial_port);
extern  int serial_tx_rx(int serial_port,char *tx_packet,int tx_len,char *rx_packet,char *digit_name);
extern  int read_and_convert(char *infile);
extern  int serial_send_file(int serial_port,char *image,int size_in_bytes,char *rx_packet);
extern  int serial_send_restart(int serial_port);
extern  int serial_send_command(int serial_port,char *command,char *image,char *rx_packet);

#endif // IMAGEUPLOADER_H_INCLUDED
