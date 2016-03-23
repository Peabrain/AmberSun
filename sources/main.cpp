#include	<clib/lowlevel_protos.h>
#include	<inline/stubs.h>
#include	<proto/intuition.h>
#include	<proto/dos.h>
#include	<stdio.h>
#include	<exec/io.h>
#include	<exec/types.h>
#include	<time.h>
#include	"screen.h"
#include	"input.h"
#include	"c2p.h"
#include	"texture.h"

double	clockToMilliseconds(clock_t ticks)
{
	return (ticks/(double)CLOCKS_PER_SEC) / 1000.0;
}

int main()
{
	SystemControl(SCON_TakeOverSys,TRUE,SCON_StopInput,TRUE);

	SCREEN	*myScreen = 0;
	C2P		*myC2P = 0;
	TEXTURE	*myTexture = 0;

	myScreen = new SCREEN();
	if(myScreen->Init())
	{
		int	SizeX = 192;
		int	SizeY = 160;

		myC2P = new C2P();
		myC2P->Init(SizeX,SizeY);

		myTexture = new TEXTURE();
		myTexture->Load("Wall.raw");

		int	xPosOrg = 0;
		int	xOrgadd = (int)(4.0f * 256);

		clock_t beginFrame = clock();

		while(1)
		{
			clock_t nextFrame = clock();
			double diffFrame = difftime(nextFrame,beginFrame);
			beginFrame = nextFrame;

			xOrgadd = (int)(256.0 * diffFrame);


			unsigned char *CnkBuffer = myC2P->GetBuffer();
			unsigned int Width = myC2P->GetWidth();
			unsigned int Height = myC2P->GetHeight();

			unsigned char *TexBuf = myTexture->GetBuffer();
			int	TexWidth = myTexture->GetWidth();
			int	TexHeight = myTexture->GetHeight();

			int	xadd = 256 * 96 / 160;
			int	xpos = 0;
			for(int j = 0;j < Width;j++)
			{
				unsigned char *p = TexBuf + (((xpos + xPosOrg) >> 8) % TexHeight) * TexWidth;
				int	yadd = 256 * 96 / 160;
				int	ypos = 0;
				for(int i = 0;i < Height;i++)
				{
					CnkBuffer[i * Width + j] = p[ypos >> 8];
					ypos += yadd;
				}
				xpos += xadd;
			}

			myC2P->Convert((unsigned int)myScreen->GetBitPlane(0) + 40 * 8 * (256 / 2 - Height / 2 - 32) + 8);

			xPosOrg += xOrgadd;

			if(isLeftMouseButtonPressed()) break;
		}

		delete myTexture;
		delete myC2P;
		myScreen->Deinit();
	}
	delete myScreen;

	SystemControl(
	SCON_TakeOverSys,FALSE,
	SCON_StopInput,FALSE
	);
}
