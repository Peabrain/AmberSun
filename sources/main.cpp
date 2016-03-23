#include	<clib/exec_protos.h>
#include	<inline/stubs.h>
#include	<proto/intuition.h>
#include	<proto/dos.h>
#include	<stdio.h>
#include	"screen.h"
#include	"input.h"

extern	unsigned int CnkBufferPtr;
extern	unsigned int PlanarScreenPtr;
extern	"C" void test();

int main()
{

	SCREEN	*myScreen = 0;

	myScreen = new SCREEN();
	if(myScreen->Init())
	{
		unsigned char *CnkBuffer = (unsigned char*)AllocMem(256*128,MEMF_ANY);
		CnkBufferPtr = (unsigned int)CnkBuffer;
		PlanarScreenPtr = (unsigned int)myScreen->GetBitPlane(0);

		int h = 0;
		while(1)
		{
//			while(!(*((unsigned char*)0xdff005) & 1))
			{
			}
//			while(*((unsigned char*)0xdff006) < 0x2a)
			{
			}

			for(int j = 0;j < 128;j++)
			for(int i = 0;i < 256;i++) CnkBuffer[j * 256 + i] = i + h;
			test();
			h += 4;

			if(isLeftMouseButtonPressed()) break;
		}

		FreeMem(CnkBuffer,256*128);
		myScreen->Deinit();
	}
	delete myScreen;
}
