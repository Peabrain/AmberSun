#include	<proto/intuition.h>
#include	<proto/dos.h>
#include	<stdio.h>
#include	"screen.h"
#include	"input.h"

int main()
{
	SCREEN	*myScreen = 0;

	myScreen = new SCREEN();
	if(myScreen->Init())
	{
		unsigned int *p[8];
		int i;
		for(i = 0;i < 8;i++) p[i] = myScreen->GetBitPlane(i);

		i = 0;
		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0x00000000;
		p[6][i] = 0x00000000;
		p[7][i] = 0x00000000;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0xffffffff;
		p[6][i] = 0x00000000;
		p[7][i] = 0x00000000;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0x00000000;
		p[6][i] = 0xffffffff;
		p[7][i] = 0x00000000;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0xffffffff;
		p[6][i] = 0xffffffff;
		p[7][i] = 0x00000000;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0x00000000;
		p[6][i] = 0x00000000;
		p[7][i] = 0xffffffff;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0xffffffff;
		p[6][i] = 0x00000000;
		p[7][i] = 0xffffffff;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0x00000000;
		p[6][i] = 0xffffffff;
		p[7][i] = 0xffffffff;
		i++;

		p[0][i] = 0x55555555;
		p[1][i] = 0x33333333;
		p[2][i] = 0x0f0f0f0f;
		p[3][i] = 0x00ff00ff;
		p[4][i] = 0x0000ffff;
		p[5][i] = 0xffffffff;
		p[6][i] = 0xffffffff;
		p[7][i] = 0xffffffff;
		i++;

		while(!isLeftMouseButtonPressed())
		{
			Delay(10);
		}

		myScreen->Deinit();
	}
}
