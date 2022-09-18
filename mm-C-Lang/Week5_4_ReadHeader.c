#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include<windows.h>

#pragma warning(disable:4996)

struct OskarActor
{
	int Index;
	int Year;
	char Age;
	char Movie[1000];
	char Name[1000];
	int Popolarity;
	struct OskarActor* next;
	struct OskarActor* prev;
};


struct OskarActor_Header
{
	int Version;
	int ItemsCount;
	char Reserved[1000];
};

typedef struct _PcxHeader
{
	BYTE	Identifier;        /* PCX Id Number (Always 0x0A) */
	BYTE	Version;           /* Version Number */
	BYTE	Encoding;          /* Encoding Format */
	BYTE	BitsPerPixel;      /* Bits per Pixel */
	WORD	XStart;            /* Left of image */
	WORD	YStart;            /* Top of Image */
	WORD	XEnd;              /* Right of Image*/
	WORD	YEnd;              /* Bottom of image */
	WORD	HorzRes;           /* Horizontal Resolution */
	WORD	VertRes;           /* Vertical Resolution */
	BYTE	Palette[48];       /* 16-Color EGA Palette */
	BYTE	Reserved1;         /* Reserved (Always 0) */
	BYTE	NumBitPlanes;      /* Number of Bit Planes */
	WORD	BytesPerLine;      /* Bytes per Scan-line */
	WORD	PaletteType;       /* Palette Type */
	WORD	HorzScreenSize;    /* Horizontal Screen Size */
	WORD	VertScreenSize;    /* Vertical Screen Size */
	BYTE	Reserved2[54];     /* Reserved (Always 0) */
} PCXHEAD;


struct Color
{
	unsigned char color;
};


struct ColorRGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

#define FILE_NAME  "c:\\a\\sample_640×426.pcx"

#define FILE_NAME3  "c:\\a\\bunny.pcx"


#define FILE_NAME2  "c:\\a\\t.pcx"

main_5_4_PCX()
{
	
	FILE* f;
	FILE* f1;
	f = fopen(FILE_NAME3, "r");
	f1 = fopen(FILE_NAME2, "wb");
	if (!f)
	{
		// error
		return;
	}

	/*
	unsigned char read;
	while (fread(&read, 1, 1, f) != NULL)
	{
		fwrite(&read, 1, 1, f1);
	}

	fclose(f1);*/
 
	PCXHEAD pcx_header;
	if (!fread(&pcx_header, sizeof(PCXHEAD), 1, f))
	{
		// error
		return;
	}

	// each pixel is one byte
	int pic_size =  sizeof(struct Color) * (pcx_header.YEnd + 1) * (pcx_header.XEnd + 1);
 
	struct Color* buffer = (struct Color*)malloc(pic_size);
	fread(buffer, pic_size, 1, f);
 
 
	fwrite(&pcx_header, sizeof(PCXHEAD), 1, f1);
	
 
	//https://stackoverflow.com/questions/46856570/how-to-create-bitmap-in-c-and-compile-with-gcc
	struct ColorRGB rgb;
	unsigned char p = 0xff;
	 
	for (int line = 0; line <= pcx_header.YEnd; line++)
	{
	//	p = line % 2 ? 255 : 1;
		for (int col = 0; col <= pcx_header.XEnd; col++)
		{
			rgb.B = 0xff;
			rgb.G = 0;
			rgb.R = 0;

			if (line > 100 && line < 150)
				p = 0xc8;
			
			//unsigned char pixel = buffer->color;
			fwrite(&p, sizeof(char), 1, f1);
		}
	}
	

	fclose(f1);





	 

	 

	fclose(f);

	
}