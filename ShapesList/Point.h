#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Shape.h"

using std::cout;
using std::endl;

class Point : public Shape
{
	protected:
		int x;
		int y;
	public:
		Point(int _x = 0, int _y = 0, const char* _color = DEFAULT_COLOR)
			: Shape(_color), x(_x), y(_y)
		{
			cout << "Point(int, int, char*)" << endl;
		}
		
		int getX() const {return x;}
		int getY() const {return y;}

		int setX(int _x) { x = _x;}
		int setY(int _y) { y = _y;}
		
		void draw() const override
		{
			//Shape::draw();
			cout << "Point. (" << x << ", " << y << ") " << color << endl;
		}
		
		~Point()
		{
			cout << "~Point()" << endl;
		}

		
				

};


#endif
