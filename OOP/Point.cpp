#include <iostream>
#include "Point.h"

using std::cout;
using std::endl;

Point::Point() : Point(0,0)// _x(0), _y(0), 
{
	cout << "Point() ctor" << endl;
}


void Point::print () const
{
	// Point* this
	printCounter++;
	cout << "Point (" << getX() << ", " << this->getY() << 
		") Printed: " << printCounter << endl;
}

void Point::setX(int x) {
	if (x >= 0)
		this->_x = x;
}

void init(Point& p) {
	p._x = -1;
	p._y = -1;
}

