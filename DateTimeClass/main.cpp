#include <iostream>
#include <cstdlib>
#include "Date.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	//Date* d1 = new Date; // heap - куча
    //d1->read();
    //d1->set(2024, 12, 10);
    
    Date* d1 = new Date(2024, 12, 10);
    d1->print();
    
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
    
    
    for(int i=0; i < 2; i++)
    	dates[i].print();

    delete d1;
    delete d2;
    return 0;
}
