#include <iostream>
#include <string>
#include "List.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;



int main(int argc, char** argv) {
	List<int>* pList = new List<int>();
	
	pList->add(new int(5));
	pList->add(new int(7));
	pList->add(new int(3));
	
	List<int>::Iterator i = pList->iterator();
	//i.start();
	while(i.hasNext())
		cout << i.value() << endl;
		
	delete pList;
	
	List<string>* courses = new List<string>();
	courses->add(new string("C Language"));
	courses->add(new string("C++ Language"));
	courses->add(new string("Java Language"));
	
	try
	{
		List<string>::Iterator c = courses->iterator();
		while(c.hasNext())
			cout << c.value() << endl;
			
		//cout << c.value() << endl;
	}
	catch(invalid_iterator_state& ex){
		cerr << ex.what() << " invalid iterator address: "
			<< ex.getInvalidIterator() << endl;
	}
	catch(const char* s) {
		cerr << "Error: " << s << endl;
	}
	/*catch(...) { // catches all exception
		cerr << "Error" << endl;
	}*/
		
	delete courses;
	
	return 0;
}
