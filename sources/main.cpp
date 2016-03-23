#include	<sys/cdefs.h>
#include	<inline/stubs.h>
#include	<proto/intuition.h>
#include	<proto/dos.h>
#include	<stdio.h>
#include	"screen.h"
#include	"input.h"

extern	unsigned int CnkBufferPtr;
extern	unsigned int PlanarScreenPtr;
extern	"C" void test();

//unsigned char	scr[40*256*8];
unsigned char	CnkBuffer[256*128];
int main()
{

	SCREEN	*myScreen = 0;

	myScreen = new SCREEN();
	if(myScreen->Init())
	{
		CnkBufferPtr = (unsigned int)&CnkBuffer[0];
		PlanarScreenPtr = (unsigned int)myScreen->GetBitPlane(0);

		Delay(200);
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
			h++;

			if(isLeftMouseButtonPressed()) break;
		}

		myScreen->Deinit();
	}
	delete myScreen;
}
