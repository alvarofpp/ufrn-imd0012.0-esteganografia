#ifndef bmp_header
#define bmp_header
typedef struct _bmp_fileheader
{
    unsigned char  fileMarker1[2]; /* 'BM' */
    unsigned char  bfSize[4]; /* File's size */
    unsigned char  unused1[2];
    unsigned char  unused2[2];
    unsigned int imageDataOffset[4]; /* Offset to the start of image data */
} bmp_fileheader;

typedef struct _bmp_infoheader
{
    unsigned int   biSize; /* Size of the info header - 40 bytes */
    signed int     width; /* Width of the image */
    signed int     height; /* Height of the image */
    unsigned short planes;
    unsigned short bitPix;
    unsigned int   biCompression;
    unsigned int   biSizeImage; /* Size of the image data */
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} bmp_infoheader;
typedef unsigned char PixelArray;

#endif