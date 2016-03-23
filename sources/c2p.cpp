#include	<clib/exec_protos.h>
#include <exec/types.h>
#include	"c2p.h"

extern	unsigned int CnkBufferPtr;
extern	unsigned int PlanarScreenPtr;
extern	unsigned short ChunkyHigh;
extern	unsigned short ChunkyWidth;
extern	"C" void ChunkyToPlanar();

C2P::C2P()
{
	Buffer = 0;
}
C2P::~C2P()
{
	if(Buffer) FreeMem(Buffer,Width * Height);
}
void	C2P::Init(int w,int h)
{
	Width = w;
	Height = h;
	Buffer = (unsigned char*)AllocMem(Width * Height,MEMF_ANY);
	CnkBufferPtr = (unsigned int)Buffer;
}
void	C2P::Convert(unsigned int pPlanarScreen)
{
	PlanarScreenPtr = pPlanarScreen;
	ChunkyHigh = Height;
	ChunkyWidth = Width/8;
	ChunkyToPlanar();
}
unsigned char *C2P::GetBuffer()
{
	return Buffer;
}
unsigned int C2P::GetWidth()
{
	return Width;
}
unsigned int C2P::GetHeight()
{
	return Height;
}
