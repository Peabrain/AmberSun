#ifndef	__SCREEN_H
#define	__SCREEN_H

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

class	SCREEN
{
public:
	SCREEN();
	~SCREEN();
	
	bool	Init();
	void	Deinit();
	unsigned int *GetBitPlane(int i);
private:
	struct	Screen *myScreen;
	unsigned int *BitPlanes[8];
};

#endif	__SCREEN_H
