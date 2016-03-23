#ifndef	__TEXTURE_H
#define	__TEXTURE_H

class	TEXTURE
{
public:
	TEXTURE();
	virtual ~TEXTURE();
	
	bool Load(const char *name);
	unsigned char *GetBuffer() {return Buffer;}
	int	GetWidth() {return Width;};
	int	GetHeight() {return Height;};
	
private:
	unsigned char *Buffer;
	int	Width;
	int	Height;
};

#endif
