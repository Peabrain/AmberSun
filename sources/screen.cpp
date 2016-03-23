#include	<stdio.h>
#include "screen.h"

SCREEN::SCREEN()
{
	myScreen = 0;
}
SCREEN::~SCREEN()
{

}

bool	SCREEN::Init()
{
	myScreen = OpenScreenTags(NULL,
	SA_Left, 0, SA_Top, 0, SA_Width, 320, SA_Height, 256,
	SA_Depth, 8,
	SA_Type, SCREENQUIET,
	SA_SysFont, 0,
	SA_ShowTitle, FALSE,
	SA_Draggable, FALSE,
	SA_Exclusive, TRUE,
	SA_Quiet, TRUE,
	SA_Interleaved, TRUE,
	SA_Behind, FALSE,
	TAG_DONE);
	if(myScreen)
	{
		int i;
		int m = 0;
		for(i = 0;i < 8;i++)
		{
			BitPlanes[i] = (unsigned int*)myScreen->BitMap.Planes[i];
			printf("Plane %i: %i\n",i,(int)(BitPlanes[i])-m);
			m = (int)BitPlanes[i];
		}

		for(i = 0;i < 256;i++)
			SetRGB32(&myScreen->ViewPort,i,i<<24,i<<24,i<<24);

	ScreenToFront(myScreen);

		return true;
	}
	return false;
}

void	SCREEN::Deinit()
{
	if (myScreen) CloseScreen(myScreen);

}

unsigned int *SCREEN::GetBitPlane(int i)
{
	return BitPlanes[i];
}
