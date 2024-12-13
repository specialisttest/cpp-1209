#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;


class Shape
{
	private:
		void copyRef(const Shape& s)
		{
			this->color = strcpy(new char[strlen(s.color)+1], s.color);
		}
	protected:
		char* color;
		
	public:
		const static char* DEFAULT_COLOR;
		
		char* getColor() const
		{ return color; }
		
		Shape(const char* _color = DEFAULT_COLOR)
			//: color(_color)
		{
			cout << "Shape (char*)" << endl;
			color = new char[strlen(_color)+1];
			strcpy(color, _color);
		}
		
		Shape(const Shape& s) 
		{
			cout << "Shape(const Shape& s)" << endl;
			copyRef(s);
		}
		Shape& operator = (const Shape& s) 
		{
			cout << "Shape& operator = (const Shape& s)" << endl;
			copyRef(s);
		}
		
		virtual void draw() const = 0;
		//{
			//cout << "Shape. " << this->getColor() << endl;
		//}
		
		virtual ~Shape()
		{
			cout << "~Shape()" << endl;
			delete color;
			color = NULL;
		}		
		
};



#endif
