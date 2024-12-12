#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const char* fname = "test.txt";

int main(int argc, char** argv) {
	ifstream f(fname, ios::in);
	char buf[100];
	while ( !f.eof() )
	//while ( !!f )
	{
		int age;
		
		/*ifstream& operator >>(ifstream&, char*)
		ifstream& operator >>(ifstream&, int)
		ifstream& operator >>(ifstream&, double)*/
		
		f >> buf >> age;
		cout << "Name: " << buf << " Age: " << age << endl;
	}
	f.close();
	
	ofstream w(fname, ios::app);
	w.seekp(0, ios::end);
	w << endl << "Alex" << setw(8) << 15 << endl;
	//w.flush();
	
	w.close();
	
	
	return 0;
}
