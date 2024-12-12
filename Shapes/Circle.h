#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

class Circle :  public Shape 
{
protected:
	int _x, _y, _r;
public:
	Circle(int x = 0, int y = 0, int r = 0,
		const char* color = DEFAULT_COLOR)
		: Shape(color), _x(x), _y(y), _r(r)
	{
		cout << "Circle(int,int,int,char*)" << endl;
	}
	
	int x() const {return _x;}
	int y() const {return _y;}
	int r() const {return _r;}
	
	Circle* x(int x) { _x = x; return this; }
	Circle* y(int y) { _y = y; return this; }	
	Circle* r(int r) { _r = r; return this; }	
	
	void draw() const override
	{
		cout << "Circle. ("	<< x() << ", " << y() << ") "
			<< "R: " << r() << " Color: " << color() << endl;
	}	
	
	void scale(double factor)
	{
		_r *= factor;
	}
	
	~Circle()  
	{
		cout << "~Circle()" << endl;
	}		
};

#endif

