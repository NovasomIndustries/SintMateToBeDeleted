#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BMP_SIZE    32768
#define DATA_OFFSET_OFFSET 0x000A
#define WIDTH_OFFSET 0x0012
#define HEIGHT_OFFSET 0x0016
#define BITS_PER_PIXEL_OFFSET 0x001C
#define HEADER_SIZE 14
#define INFO_HEADER_SIZE 40

unsigned short bmpfile[MAX_BMP_SIZE];

int main (int argc, char **argv)
{
char        *infile = NULL;
char        *outfile = NULL;
int         c,read_elements,i,k,dataOffset;
unsigned short  bitsPerPixel;
FILE        *fpin , *fpout;

    while ((c = getopt (argc, argv, "abi:o:")) != -1)
    switch (c)
    {
        case 'i':       infile = optarg;  break;    // input file
        case 'o':       outfile = optarg;  break;    // output file
        case '?':       if (optopt == 'i')
                            fprintf (stderr, "Option -%c requires the input file name.\n", optopt);
                            else if (isprint (optopt))
                            fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                            else
                            fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
                            return 1;
        default:        return -1;
    }

    fpin = fopen (infile, "r");
    if ( fpin == NULL )
    {
        printf( "Unable to open %s for read\n",infile ) ;
        return -1;
    }

    fseek(fpin, BITS_PER_PIXEL_OFFSET, SEEK_SET);
    fread(&bitsPerPixel, 2, 1, fpin);
    if ( bitsPerPixel != 16 )
    {
        printf("Required 16 bpp image, found %d image\n",bitsPerPixel) ;
        fclose(fpin);
    }

    fseek(fpin, DATA_OFFSET_OFFSET, SEEK_SET);
    fread(&dataOffset, 4, 1, fpin);
    fseek(fpin, dataOffset, SEEK_SET);
    read_elements = fread(bmpfile, 2, MAX_BMP_SIZE, fpin);
    printf( "Found %d %d bit pixels ( %d bytes )\n",read_elements,bitsPerPixel,read_elements*2) ;
    fclose(fpin);
    fpout = fopen (outfile, "w+");
    if ( fpout == NULL )
    {
        printf( "Unable to open %s for write\n",outfile ) ;
        return -1;
    }
    fprintf(fpout,"uint16_t D1red[%d] = \n",read_elements);
    fprintf(fpout,"{\n");
    k=0;
    for(i=0;i<read_elements;i++)
    {
        if ( i != read_elements-1)
            fprintf(fpout,"0x%04x,",bmpfile[i]);
        else
            fprintf(fpout,"0x%04x",bmpfile[i]);
        k++;
        if ( k == 8 )
        {
            k=0;
            fprintf(fpout,"\n");
        }
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    printf( "File %s written\n",outfile ) ;
    return 0;
}
