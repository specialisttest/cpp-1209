#include <cmath>
#include <iostream>
#include "mylib.h"
#include "Point.h"

using std::cout;
using std::endl;

double distance(const Point& p1, const Point& p2) {
	//p2.setX(300);
	return sqrt( pow(p1.getX()-p2.x(), 2) + pow(p1.y()-p2.y(), 2) );
}

int main(int argc, char** argv) {
	Point p; // 1
	//p.setX(10);
	//p.setY(20);
	
	
	
	//p.x = 10;
	//p.y = 20;
	//p.Point::print();
	p.print(); // print(&p)
	
	Point& ref = p;
	ref.print();
	
	Point* pointer = &p;
	
	//pointer->Point::print();
	pointer->print(); // (*pointer).print();
	
	Point* p2 = new Point(100, 200); // 2
	
	//p2->x(100)->y(200);
	
	//p2->x(100);
	//p2->y(200);
	
	p2->print();
	init(*p2);
	Transform t;
	
	t.transit(*p2, -100, -100);
	
	p2->print();
	
	cout << distance(p, *p2) << endl;
	
	delete p2;
	
	Point(33,66).print();
	
	(new Point())->print();
	
	
	
	return 0;
}
