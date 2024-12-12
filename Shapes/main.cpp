#include <iostream>
#include "Shape.h"
#include "Point.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	Point* p1 = new Point(10, 20);
	
	//p1->draw(); // Point::draw()
	//p1->Shape::draw();
	//p1->Point::draw();
	Point& pr = *p1;

	// ������� �������������� ��������� (������) ��������� ���� 
	// � �������� (������) ������������� ���� - ��������� �������� �� �������� � ������
	Shape& sr = pr;
	Shape* s1 = p1;
	
	s1->draw(); // ????
	//s1->x();
	//Point* p2 = (Point*)s1;
	Point* p2 = dynamic_cast<Point*>(s1);
	p2->x();
	// Shape ss; // error
	
	//sr.draw();
	// VMT
	/*	Class	Method	Address
		Shape	draw	XXXX
		Point	draw	YYYY
	
	*/
	
	//Point px(1,1);
	//Shape sx = px; //
	//px.draw();
	
	
	//cout << p1->x() << ", " << p1->y() << " " << p1->color() <<endl;
	
	delete p1;
	
	
	return 0;
}
