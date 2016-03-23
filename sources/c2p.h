#ifndef	__C2P_H
#define	__C2P_H

class	C2P
{
public:
	C2P();
	virtual ~C2P();
	
	void	Init(int w,int h);
	void	Convert(unsigned int pPlanarScreen);
	unsigned char *GetBuffer();
	unsigned int GetWidth();
	unsigned int GetHeight();

private:
	unsigned char *Buffer;
	int				Width;
	int				Height;
};

#endif	__C2P
