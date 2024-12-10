#include <iostream>
#include "Date.h"

void Date::set(int _year, int month, int day)
{
    if (_year >= 1 && _year <= 2100)
        this->_year = _year;
    if (month >= 1 && month <=12)
        this->_month = month;
    if (day >= 1 && day <= 31)
        this->_day = day;
}

using std::cout;
using std::cin;
using std::endl;

void Date::print() const
{
    cout << _year << '.' << _month << '.' << _day << endl;
}

void Date::read()
{
    cout << "Year (1-2100): ";
    int year;
    cin >> year;
    cout << "Month (1-12): ";
    int month;
    cin >> month;
    cout << "Day (1-31): ";
    int day;
    cin >> day;
    set(year, month, day);
}

int Date::compareTo(const Date& d) const {
    if (this->_year == d._year && this->_month == d._month &&
        this->_day == d._day) return 0;
        
    if (this->_year > d._year) return 1;  
    if (this->_year == d._year) 
    {
    	if (this->_month > d._month) return 1;
        if (this->_month == d._month)
            if (this->_day > d._day) return 1;
	}
	
	return -1;
	
}

int compareDate(const void* d1, const void* d2)
{
	return static_cast<const Date*>(d1)->compareTo(*static_cast<const Date*>(d2));
}
