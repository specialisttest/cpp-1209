#ifndef __COORDS_H__
#define __COORDS_H__

class Coords {
private:
	class CoordinateSystem {
			CoordinateSystem(Coords* c) {
				c->z = 0;
			}
			friend class Coords;
	};
	
	int z;
public :
	
	int _x, _y;
	Coords(int x = 0, int y = 0)
		: _x(x), _y(y), z(1)
	{
		CoordinateSystem s(this);
	}
	int getZ() {return z;}
	
};

#endif
