#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

using std::cout;
using std::endl;

class Point;
typedef Point* PPoint;

void init(Point& p);

class Point
{
private:
	int _x;
	int _y;
	mutable int printCounter = 0;
	
	PPoint parent;
	
// protected:
	
public:
	
	Point();
	
	Point(int x, int y) : _x(x), _y(y)
	{
		cout << "Point(int,int) ctor" << endl;
	}
	
	
	
	void print () const ;
	
	int x() const { return _x; }
	Point* x(int x) { setX(x); return this; }
	int y() const {return _y; }
	Point* y(int y) { setY(y); return this; }
	
	int getX() const { return _x; } // inline
	int getY() const { return _y; }
	
	void setX(int x);
	void setY(int y) {
		if (y >= 0)
			this->_y = y;
	}
	
	friend void init(Point& p);
	friend class Transform;
	
};

class Transform {
	public:
		void transit(Point& p, int dx, int dy) {
			p._x += dx;
			p._y += dy;
		}
};




#endif
