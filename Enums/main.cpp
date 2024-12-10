#include <iostream>

using std::cout;
using std::endl;

// old C style
//enum Colors : int { Red, Green, Blue };

// C++ style
enum class Colors : int { Red = 1, Green = 2, Blue = 4 };
enum class ArOperation : char { Add = '+', Minus = '-', Multiply = '*', Divide ='/'};


//using enum Colors;
using Colors::Green;

int main(int argc, char** argv) {
	
	//int a = 5;
	//Colors c = Colors::Green;
	//Colors c {Colors::Green};
	Colors c {Green};
	
	
	int q = 2;
	c = (Colors)q;
	int k = (int)c;
	
	cout << sizeof(c) << endl;
	cout << (int)c << endl;
	
	ArOperation op {ArOperation::Multiply};
	cout << static_cast<char>(op) << endl;
	
	
	
	return 0;
}
