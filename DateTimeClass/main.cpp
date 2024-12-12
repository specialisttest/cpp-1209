#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Date.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

int main(int argc, char** argv) {
	/*Date* d1 = new Date; // heap - куча
	cin >> *d1;
    //d1->read();
    //d1->set(2024, 12, 10);
    
    //Date* d1 = new Date(2024, 12, 10);
    //d1->print();
    cout << *d1 << endl;
    
    Date* d2 = new Date;
    //d2->set(2021, 5, 1);
    
    cout << std::boolalpha;
    cout << d1->equals(d2) <<endl;
    cout << d1->greater(d2) <<endl;
    cout << d1->less(d2) <<endl;
    
    cout << (*d1 == *d2) << endl;
    cout << (*d1 > *d2) << endl;
    cout << (*d1 < *d2) << endl;    
    
    Date dates[2] = {*d1, *d2};
    for(int i=0; i < 2; i++)
    	dates[i].print();
    	
    qsort(dates, 2, sizeof(Date), compareDate );
    
    ofstream f("dates.txt");
    for(int i=0; i < 2; i++) {
    	dates[i].print();
    	f << dates[i] << endl;
	}
	f.close();
	*/
	ifstream inp("dates.txt", ios::in );
	while(!inp.eof()) {
		Date d;
		inp >> d;
		cout << d << endl;
	}
	inp.close();
    	

    //delete d1;
    //delete d2;
    return 0;
}
