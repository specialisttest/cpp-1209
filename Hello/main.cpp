#include <cstdlib> // stdlib.h
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct Course
{
	const char* title;
	int   length;
};


void print(const Course& c, const char* delimeter = ", ")
{
	cout << c.title << delimeter << c.length << endl;
}
/*void print(const Course& c)
{
	print(c, ", ");
}*/

// overloading
int my_min(int a, int b)
{
	return (a < b) ? a : b;
}

double my_min(double a, double b)
{
	return (a < b) ? a : b;
}

int main(int argc, char** argv) {
	
	system("chcp 1251 > nul");
	//setlocale(LC_ALL, "Russian");
	
	cout << "Ваше имя: ";
	char name[20];
	cin >> name;
	
	cout << "Привет, " << name << "!" << endl;
	
	
	
	int x = 5; // строчный комментарий
	/*
		блочный комментарий
		// строчный комментарий
	*/
	
	int* px = &x;
	std::cout << px << std::endl;
	std::cout << *px << std::endl;
	
	int& y = x;
	y++; // (*px)++;
	std::cout << x << std::endl;
	x++;
	std::cout << y << std::endl;
	
	
	std::cout << "Hello ugly world!" << std::endl;
	
	/*Course c1;
	c1.title = "C++ Language";
	c1.length = 40;*/

	int Course::* pLength = &Course::length;
	
	Course c1 = {"C++ Language", 40};
	cout << c1.*pLength << endl; // c1.length
	
	print(c1);
	print(c1, ", ");
	print(c1, " - ");
	
	int m = my_min (10, 5);
	cout << m << endl;
	
	double md = my_min (10.5, 5.9);
	cout << md << endl;
	
	return 0;
}
