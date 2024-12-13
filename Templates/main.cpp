#include <iostream>
#include <typeinfo>

#include "ReadonlyStorage.h"

using std::cout;
using std::endl;

/*
int max (int x, int y)
{
	return (x > y) ? x : y;
}
double max (double x, double y)
{
	return (x > y) ? x : y;
}*/

template<typename T>
T max (T x, T y)
{
	return (x > y) ? x : y;
}

//template<typename T>
//T min (T x, T y)
auto min (const auto& x, const auto& y)
{
	return (x < y) ? x : y;
}

template<typename T, typename T1>
decltype(auto) add(T x, T1 y){
	return x + y;
}

template<typename T = int>
T Double(int x)
{
	return 2*x;
}

template<typename T, size_t N = 1>
void printArray(const T (&)[N]);

/*void printArray(const int* arr, size_t N) {
	for(size_t i =0; i < N; i++)
		cout << arr[i] << endl;
}*/

/*void printArray(const int arr[3]) {
	for(size_t i =0; i < 3; i++)
		cout << arr[i] << endl;
}
void printArray(const int arr[4]) {
	for(size_t i =0; i < 3; i++)
		cout << arr[i] << endl;
}
void printArray(const char** arr, size_t N) {
	for(size_t i =0; i < N; i++)
		cout << arr[i] << endl;
}*/

template<typename T, size_t N>
void printArray(const T (&arr)[N]) {
	for(size_t i =0; i < N; i++)
		cout << arr[i] << endl;
}

int main(int argc, char** argv) {
	cout << min (1, 5) << endl;
	cout << max (1, 5) << endl;
	cout << max<double> (10, 2.5) << endl;
	cout << add<double, int> (10.5, 5) << endl;
	cout << add (10.5, 5.2f) << endl;
	cout << add (10, 5.2) << endl; // add<int,double> (10, 5.2)
	
	const int numbers[5] { 100, 200, 300, 400 };
	const int numbers1[] { 100 };
	const char* names[] { "Sergey", "Tom"};
	
	printArray(numbers);
	printArray(names);
	printArray(numbers1);
	
	cout << Double<double>(2.3)<< " type: " << typeid(Double<double>(2.3)).name() << endl;
	
	ReadonlyStorage<int> r1(5);
	ReadonlyStorage<double> r2(2.3);
	cout << r1.getData() << endl;
	cout << (r1+r1).getData() << endl;
	cout << r2.getData() << endl;
	cout << (r2+r2).getData() << endl;
	
	
	//cout << max<int> (1, 5) << endl;
	//cout << max<double> (10.5, 2.5) << endl;
}
