#ifndef __IMOVEABLE_H__
#define __IMOVEABLE_H__

class IMoveable
{
public:
	virtual void moveBy(int dx, int dy) = 0;
	virtual void moveTo(int x, int y) = 0;
};

#endif
