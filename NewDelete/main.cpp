#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	
	//int* pi = new int;
	int* pi = new int(200); // ������ ���������� ��� ���� int, ������� ���������������� ��������� 200
	
	cout << *pi << endl;
	delete pi;
	pi = NULL;
	//delete pi;
	//if ( pi != NULL)
	
	//pi[0] = 100;
	//pi[1] = 200;
	int* pnums = new int[5]; // ���������� ������ ��� 5 int
	// std::bad_alloc // ���������� ��� ������������� ���������
	
	for(int i=0; i < 5; i++)
		cout << "pnums [" << i << "] = " << pnums[i] << endl;
	
	delete[] pnums;
	
	
	return 0;
}
