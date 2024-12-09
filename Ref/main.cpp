#include <iostream>

//using namespace std;
using std::cout;
using std::endl;


double a = 3.1415;

void swap_int(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

// перегрузка ф-й - overloading
inline void swap_int(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int main(int argc, char** argv) {
	int a = 10;
	int b = 20;
	
	cout << "a: " << a << " b: " << b << endl;
	//swap_int(&a, NULL); // runtime error
	//swap_int(&a, &b);
	swap_int(a, b);
	
	cout << ::a << endl;
	
	
	
	std::cout << "a: " << a << " b: " << b << endl;
	
	return 0;
}
