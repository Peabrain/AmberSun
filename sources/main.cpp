#include	<clib/lowlevel_protos.h>
#include	<inline/stubs.h>
#include	<proto/intuition.h>
#include	<proto/dos.h>
#include	<stdio.h>
#include	"screen.h"
#include	"input.h"
#include	"c2p.h"


int main()
{
	SystemControl(
	SCON_TakeOverSys,TRUE,
	SCON_StopInput,TRUE
	);

	SCREEN	*myScreen = 0;
	C2P		*myC2P = 0;

	myScreen = new SCREEN();
	if(myScreen->Init())
	{
		int	SizeX = 192;
		int	SizeY = 160;
		myC2P = new C2P();

		myC2P->Init(SizeX,SizeY);

		int h = 0;
		while(1)
		{
			unsigned char *CnkBuffer = myC2P->GetBuffer();
			unsigned int Width = myC2P->GetWidth();
			unsigned int Height = myC2P->GetHeight();
			for(int j = 0;j < Width;j++)
				for(int i = 0;i < Height;i++)
					CnkBuffer[i * Width + j] = j + h;

			myC2P->Convert((unsigned int)myScreen->GetBitPlane(0) + 40 * 8 * (256 / 2 - Height / 2 - 32) + 8);

			h += 4;

			if(isLeftMouseButtonPressed()) break;
		}

		delete myC2P;
		myScreen->Deinit();
	}
	delete myScreen;

	SystemControl(
	SCON_TakeOverSys,FALSE,
	SCON_StopInput,FALSE
	);
}
