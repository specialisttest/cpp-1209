#include <ios>
#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;
using std::type_info;

struct Course
{
	const char* title;
	int   length;
};

int main(int argc, char** argv) {
	double x = 2.5;
	
	cout << typeid(x).name() << endl;
	cout << typeid(int*).name() << endl;
	cout << typeid(Course).name() << endl;
	
	double n = x;
	int n2 = 6;
	
	const type_info& t = typeid(double*);
	cout << (typeid(n) == typeid(x)) << endl;
	cout << (typeid(n2) == typeid(x)) << endl;
	
	double* pn = &n;
	void* pp = pn;
	double* pn2 = (double*)pp; // c
	
	double* pn3 = static_cast<double*>(pp); // c++
	
	const int* rn2 = &n2;
	//(*rn2)++;
	int* rrn2 = const_cast<int*>(rn2);
	(*rrn2)++;
	cout << n2 << endl;
	// dynamic_cast 
	// reinterpret_cast
	
	long long y = reinterpret_cast<long long>(rrn2);
	cout << y << endl;
	
	bool a = true;
	bool b = false;
	
	// !
	// &&
	// ||
	bool c = !(a || b);
	
	cout << std::boolalpha << c << endl;
	
	
	
	
	
	
	return 0;
}
