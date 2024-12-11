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
	
	int* buffer = NULL;
	
	const int _z = 0;
	
	static int objectCounter;
	
// protected:
	
public:
	static const int DEFAULT_Z = 0;
	
	// default ctor
	Point();
	
	// обычный ctor
	Point(int x, int y) : _x(x), _y(y), _z(DEFAULT_Z)
	{
		cout << "Point(int,int) ctor" << endl;
		buffer = new int[100];
		objectCounter++; //Point::objectCounter++;
	}
	
	// отключение автоматического создания копирующего конструктора
	// Point(const Point& p) = delete;
	
	// copy ctor
	Point(const Point& p)
		: _x(p._x), _y(p._y), printCounter(0)
	{
		cout << "ctor Point(const Point&)" << endl;
		buffer = new int[100];
		objectCounter++;
	}
	
	// conv ctor (implicit)
	// Point(int k) 
	
	// conv ctor (explicit)
	explicit Point(int k) 
		: Point(k, k)
	{
		cout << "ctor Point(int)" << endl;
	}
	
	~Point() {
		cout << "~Point()" << endl;
		delete[] buffer;
		objectCounter--;
	}
	
	Point& operator=(const Point& p) {
		_x = p._x;
		_y = p._y;
		printCounter = 0;
		cout << "Point& operator=(const Point& p)" << endl;
		return *this;
	}
	
	void print () const;
	
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
	
	Point add(const Point& p) const;
	//Point operator+(const Point& p) const;  // Point + Point ( *this + p)
	Point operator-() {
		return Point(-x(), -y());
	}
	Point operator-(const Point& p) {
		return Point(x() - p.x(), y() - p.y());
	}
	
	//int operator [](int i); // rvalue
	int& operator [](int i); // lvalue
	
	Point& operator +=(const Point& p);
	
	Point& operator ++(); // prefix
	Point operator ++(int); // suffix
	
	
	static int getObjectCounter() { return objectCounter; }
	
	friend void init(Point& p);
	friend class Transform;
	//friend Point operator+(const Point& p1, const Point& p2);
	
};

Point addPoints(const Point& p1, const Point& p2);
Point operator+(const Point& p1, const Point& p2);
Point operator+(const Point& p1, int x);
Point operator+(int x, const Point& p1);

bool operator ==(const Point& p1, const Point& p2);
bool operator !=(const Point& p1, const Point& p2);


std::ostream& operator <<(std::ostream& s, const Point& p);
std::istream& operator >>(std::istream& s, Point& p);

class Transform {
	public:
		void transit(Point& p, int dx, int dy) {
			p._x += dx;
			p._y += dy;
		}
};




#endif
