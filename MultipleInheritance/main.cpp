#include <iostream>
#include "Person.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	Student* s1 = new Student;
	s1->Name = "Student 1";
	s1->Branch = "IT";
	s1->Person::Income = 100;
	s1->Income = 50; //s1->Student::Income = 50;
	cout << s1->Name << " : " << s1->TotalIncome() << endl;
	Person* p1 = s1;
	//p1->Income = 75; // Person::Income
	p1->setIncome(75); // Student::Income
	cout << s1->Name << " : " << s1->TotalIncome() << endl;
	
	Worker* w1 = dynamic_cast<Worker*>(s1); // runtime conv
	if (w1 != NULL)
		cout << w1->Name << " : "  << w1->TotalIncome() << endl;
	else
		cout << s1->Name << " is not working" << endl;
	
	
	WorkingStudent* ws1 = new WorkingStudent;
	// ws1->Income = 100; // error
	//((Person*)((Student*)ws1))->Income = 100;
	//((Person*)((Worker*)ws1))->Income = 200;
	ws1->Person::Income = 200;
	
	ws1->Name = "Working Student 1";
	
	ws1->Student::Income = 50;
	ws1->Worker::Income  = 60;
	
	cout << ws1->TotalIncome() << endl; 
	cout << ws1->Name << endl; 
	
	Person* p2 = dynamic_cast<Person*>(ws1);
	cout << p2->TotalIncome() << endl; 
	
	
	return 0;
}
