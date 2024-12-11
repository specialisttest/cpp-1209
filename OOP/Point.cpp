#include <iostream>
#include <stdexcept>
#include "Point.h"

using std::cout;
using std::endl;


int Point::objectCounter = 0;

Point::Point() : Point(0,0)// _x(0), _y(0), 
{
	cout << "Point() ctor" << endl;
}

Point Point::add(const Point& p) const {
	return Point( x() + p.x(), y() + p.y() );
}
/*Point Point::operator +(const Point& p) const {
	return Point( _x + p.x(), y() + p.y() );
}*/

Point addPoints(const Point& p1, const Point& p2)
{
 	return Point(p1.x() + p2.x(), p1.y() + p2.y());
}

Point operator+(const Point& p1, const Point& p2)
{
 	//return Point(p1._x + p2.x(), p1.y() + p2.y());
 	return Point(p1.x() + p2.x(), p1.y() + p2.y());
}

Point operator+(const Point& p1, int x) {
	return Point(p1.x() + x, p1.y() + x);
}
Point operator+(int x, const Point& p1) {
	return p1 + x;
}

int& Point::operator [](int i) {
	switch (i) {
		case 0 : return _x;
		case 1 : return _y;
		default:
			// std::cerr << "Invalid point coords index" << endl;
			throw std::out_of_range("Point index out of range");
	}
}
Point& Point::operator +=(const Point& p) {
	this->_x += p._x;
	this->_y += p._y;
	return *this;
}
bool operator ==(const Point& p1, const Point& p2) {
	return (p1.x() == p2.x() && p1.y() == p2.y());
}

bool operator !=(const Point& p1, const Point& p2) {
	return !(p1 == p2);
}

// prefix
Point& Point::operator ++() {
	_x++; _y++;
	return *this;
}

// suffix (postfix)
Point Point::operator ++(int) {
	Point pv(*this);
	/*this->_x++;
	this->_y++;*/
	++(*this);
	return pv;
}

void Point::print () const
{
	// Point* this
	printCounter++;
	cout << "Point (" << getX() << ", " << this->getY() << 
		") Printed: " << printCounter << endl;
}

std::ostream& operator <<(std::ostream& s, const Point& p) 
{
	s << "(" << p.getX() << ", " << p.getY() << ")";
	return s;
}
std::istream& operator >>(std::istream& s, Point& p)
{
	int x, y;
	s >> x;
	s >> y;
	p.setX(x);
	p.setY(y);
	return s;
}

void Point::setX(int x) {
	if (x >= 0)
		this->_x = x;
}

void init(Point& p) {
	p._x = -1;
	p._y = -1;
}



