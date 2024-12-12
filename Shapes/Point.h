#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

class Point : public Shape
{
protected:
	int _x, _y;

public:	
	Point(int x = 0, int y = 0, const char* color = DEFAULT_COLOR)
		: Shape(color), _x(x), _y(y)
	{
		cout << "Point (int, int, char*) ctor" << endl;
	}
	
	void moveBy(int dx, int dy)
	{
		_x += dx; _y += dy;
	}
	
	void draw() const override
	{
		std::cout << "Point (" << x() << ", " << y() << ")  " 
			<< "Shape (" << this->Shape::_x << ", " << this->Shape::_x << ")  " 
			<< color() << std::endl;
			
		//this->Shape::draw();
	}
	
		
	int x() const {return _x;}
	int y() const {return _y;}
	
	Point* x(int x) { _x = x; return this; }
	Point* y(int y) { _y = y; return this; }
	
	~Point()
	{
		cout << "~Point()" << endl;
	}
};


#endif
