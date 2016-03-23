#include	<clib/exec_protos.h>
#include	<clib/lowlevel_protos.h>
#include	<inline/stubs.h>
#include	<proto/intuition.h>
#include	<proto/dos.h>
#include	<stdio.h>
#include	"screen.h"
#include	"input.h"

extern	unsigned int CnkBufferPtr;
extern	unsigned int PlanarScreenPtr;
extern	"C" void ChunkyToPlanar();

int main()
{
	SystemControl(
	SCON_TakeOverSys,TRUE,
	SCON_StopInput,TRUE
	);

	SCREEN	*myScreen = 0;

	myScreen = new SCREEN();
	if(myScreen->Init())
	{
		unsigned char *CnkBuffer = (unsigned char*)AllocMem(192*160,MEMF_ANY);
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

			for(int j = 0;j < 160;j++)
			for(int i = 0;i < 192;i++) CnkBuffer[j * 192 + i] = i + h;
			ChunkyToPlanar();
			h += 4;

			if(isLeftMouseButtonPressed()) break;
		}

		FreeMem(CnkBuffer,192*160);
		myScreen->Deinit();
	}
	delete myScreen;

	SystemControl(
	SCON_TakeOverSys,FALSE,
	SCON_StopInput,FALSE
	);
}
