#include	"input.h"

bool	isLeftMouseButtonPressed()
{

	unsigned char *v = (unsigned char*)0xbfe001;
	if(!((*v) & (1<<6))) return true;
	return false;
}
