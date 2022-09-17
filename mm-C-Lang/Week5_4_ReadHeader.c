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

#define FILE_NAME  "c:\\a\\sample_640×426.pcx"
#define FILE_NAME2  "c:\\a\\t.pcx"

main()
{
	
	FILE* f;
	FILE* f1;
	f = fopen(FILE_NAME, "r");
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
	
 


	 
	for (int line = 0; line <= pcx_header.YEnd; line++)
	{
		for (int col = 0; col <= pcx_header.XEnd; col++)
		{
			unsigned char p = 255;
			p = line % 2?100 : 5;
			//unsigned char pixel = buffer->color;
			fwrite(&p, 1, 1, f1);
		}
	}
	

	fclose(f1);





	 

	 

	fclose(f);

	
}