#include	<clib/exec_protos.h>
#include <exec/types.h>
#include	<stdio.h>
#include	"texture.h"

TEXTURE::TEXTURE()
{
	Buffer = 0;
}
TEXTURE::~TEXTURE()
{
	if(Buffer) FreeMem(Buffer,Width * Height);
}
bool	TEXTURE::Load(const char *name)
{
	if(FILE *f = fopen(name,"rb"))
	{
		Width = 96;
		Height = 96;
		fseek(f,0,SEEK_END);
		int len = ftell(f);
		rewind(f);

		printf("open file %i\n",len);

		Buffer = (unsigned char*)AllocMem(Width * Height,MEMF_ANY);
		fread(Buffer,1,Width * Height,f);

		fclose(f);
		return true;
	}
	return false;
}
