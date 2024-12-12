#include <cmath>
#include <iostream>
#include <fstream>

#include "mylib.h"
#include "Point.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios;


double distance(const Point& p1, const Point& p2) {
	//p2.setX(300);
	return sqrt( pow(p1.getX()-p2.x(), 2) + pow(p1.y()-p2.y(), 2) );
}

int main(int argc, char** argv) {
	//Point::objectCounter = 100;
	cout << "Total points: " << Point::getObjectCounter() << endl; // 0
	
	Point p(0, 0); // 1
	
	//p.Point::getObjectCounter();
	
	// p.~Point(); // explicit destructor call
	
	//p.setX(10);
	//p.setY(20);
	
	//p.x = 10;
	//p.y = 20;
	//p.Point::print();
	p.print(); // print(&p)
	p.x(10)->y(20);
	p.print();
	Point p1 = p; // 2

	p1.print();
	cout << &p << endl << &p1 << endl;

	cout << "Total points: " << Point::getObjectCounter() << endl;
	
	Point& ref = p;
	ref.print();
	
	Point* pointer = &p;
	
	//pointer->Point::print();
	pointer->print(); // (*pointer).print();
	
	Point* p2 = new Point(100, 200); // 3
	
	//p2->x(100)->y(200);
	
	//p2->x(100);
	//p2->y(200);
	
	p2->print();
	init(*p2);
	Transform t;
	
	cout << "Total points: " << Point::getObjectCounter() << endl; // 3
	
	t.transit(*p2, -100, -100);
	
	p2->print();
	
	cout << distance(p, *p2) << endl;
	
	delete p2;
	
	cout << "Total points: " << Point::getObjectCounter() << endl; //2

	
	Point(33,66).print();
	
	cout << "Total points: " << Point::getObjectCounter() << endl; //2
	
	(new Point())->print();
	
	// implicit
	//Point p3 = 5; // Point p3(5)
	
	// explicit
	Point p3 = static_cast<Point>(5); // Point p3(5)
	p3.print();	
	
	p3 = p;
	p3.print();
	
	cout << "Total points: " << Point::getObjectCounter() << endl; //2
	
	Point px1(10, 20);
	Point px2(100, 200);
	//Point px3 = px1.add(px2);
	//Point px3 = addPoints(px1, px2);
	//Point px3 = px1.operator+(px2);
	Point px3 = px1 + px2;
	
	px1.print();
	px2.print();
	px3.print();
	
	Point px4 = 5 + px1;
	px4.print();
	
	Point px5 = -px4;
	px5.print();
	
	Point px6 = px2 - px1;
	px6.print();
	
	px1[0] = 200;
	cout << px1[0] << ", " << px1[1] << endl;
	//       px1.x             px1.y
	
	px6.print();
	px2.print();
	px6 += px2; 
	//px6 = px6 + px2;
	px6.print();
	
	Point pz1(5, 6);
	Point pz2(5, 6);
	
	pz1.print();
	pz2.print();
	bool r = (pz1 != pz2);
	cout << std::boolalpha << r << endl;
	
	//++pz1;
	pz2 = pz1++;
	//pz1.print();
	//pz2.print();
	std::clog << pz1 << endl;
	cout << "Enter coords (x,y): ";
	Point py1;
	cin >> py1;
	
	cout << py1 << endl;
	
	ofstream w("points.txt", ios::trunc);
	w << pz1 << endl << py1 << endl;
	w.close();
	
	
	
	return 0;
}
