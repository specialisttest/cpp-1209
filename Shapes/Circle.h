#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>
#include "Shape.h"
#include "Coords.h"
#include "IScaleable.h"

using std::cout;
using std::endl;

class Circle :  public virtual Shape,
	public IScaleable, /* should be first for VS*/
	public IMoveable,
	private /*protected*/ Coords
{
protected:
	int _r;
public:
	Circle(int x = 0, int y = 0, int r = 0,
		const char* color = DEFAULT_COLOR)
		: Coords(x,y), Shape(color), /*_x(x), _y(y),*/ _r(r)
	{
		cout << "Circle(int,int,int,char*)" << endl;
	}
	
	int x() const {return this->Coords::_x;}
	int y() const {return this->Coords::_y;}
	int r() const {return _r;}
	
	Circle* x(int x) { this->Coords::_x = x; return this; }
	Circle* y(int y) { this->Coords::_y = y; return this; }	
	Circle* r(int r) { _r = r; return this; }	
	
	void draw() const override
	{
		cout << "Circle. ("	<< x() << ", " << y() << ") "
			<< "R: " << r() << " Color: " << color() << endl;
	}	
	
	void scale(double factor) override
	{
		_r *= factor;
	}
	
	void moveBy(int dx, int dy) override {
		Shape::moveBy(dx, dy);
		this->Coords::_x += dx; this->Coords::_y += dy;
	}
	void moveTo(int x, int y) override {
		
		this->Coords::_x += x; this->Coords::_y += y;
	}
	
	~Circle()  
	{
		cout << "~Circle()" << endl;
	}		
};

#endif

