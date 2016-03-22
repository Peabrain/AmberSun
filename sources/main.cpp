#include <proto/intuition.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <intuition/screens.h>
#include <graphics/gfxbase.h>
#include <graphics/gfx.h>
#include <graphics/view.h>
#include <graphics/rastport.h>

#include <exec/types.h>
#include <graphics/gfxmacros.h>
#include <intuition/IntuitionBase.h>
#include <intuition/screens.h>
#include <libraries/dos.h>

int main()
{
	int	i;
/* makes a copy of the Screen struct(ure) and calls that copy myScreen, changes are made to this copy */
	struct	Screen *myScreen;
	struct	Viewport *myViewport;
/* you can call the copy 'myScreen' any name you like, as long as you use it throughout the program consistently */

/* describe how 'myScreen' looks like by using tags SA_? */
	myScreen = OpenScreenTags(NULL,
	SA_Left, 0, SA_Top, 0, SA_Width, 320, SA_Height, 256,
	SA_Depth, 8,
	SA_Type, SCREENQUIET,
	SA_SysFont, 0,
	SA_ShowTitle, FALSE,
	SA_Draggable, FALSE,
	SA_Exclusive, TRUE,
	SA_Quiet, FALSE,
	TAG_DONE);

	for(i = 0;i < 256;i++)
		SetRGB32(&myScreen->ViewPort,i,i<<24,i<<24,i<<24);

//	SetRGB32(&myScreen->ViewPort,1,255,255,255);

	unsigned int *p[8];
	for(i = 0;i < 8;i++) p[i] = (unsigned int*)myScreen->BitMap.Planes[i];

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

	Delay(500);

/* check if screen open, returns TRUE for success and FALSE for failure, if so, use CloseScreen() command to close */
	if (myScreen) CloseScreen(myScreen);
}
