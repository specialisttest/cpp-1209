//#pragma once
#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>
#include <string>
#include "IMoveable.h"

using std::string;
using std::cout;
using std::endl;

class Shape: public IMoveable
{

protected:
	string* _color;
	int _x = -1;
	int _y = -1;
	
	
public:
	const static char* DEFAULT_COLOR;
	
	string color() const {
		return *_color;
	}
	
	Shape(string color) {
		_color = new string(color);
		cout << "Shape (string) ctor" << endl;
	}
	Shape(const char* color = DEFAULT_COLOR)
	{
		_color = new string(color);
		cout << "Shape (char*) ctor" << endl;
	}
	
	//Shape(const Shape&) = delete;
	
	Shape(const Shape& s) {
		_color = new string(s.color());
	}
	
	Shape& operator = (const Shape& s) {
		_color = new string(s.color());
		return *this;
	}
	
	virtual void draw() const = 0;
	//{
		/*std::cout << "Shape (" << _x << ", " << _y << ") " 
			<< color() << std::endl;*/
	//}
	
	//virtual ~Shape() {};
	//virtual ~Shape() = default;
	
	void moveBy(int dx, int dy) override
	{
		cout << "Shape::moveBy(int, int)" << endl;
		_x += dx; _y += dy;
	}
	void moveTo(int x, int y) override
	{
		_x = x; _y = y;
	}	
	
	
	virtual ~Shape() {
		delete _color;
		cout << "~Shape()" << endl;
	}
	
};


#endif
