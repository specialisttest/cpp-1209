#include <iostream>
#include <iomanip>
#include <ctime>
#include "Date.h"

Date::Date()
{
	time_t t = time(NULL);
	struct tm now = *localtime(&t);
	set(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
	/*_year = now.tm_year + 1900;
	_month = now.tm_mon + 1;
	_day = now.tm_mday;*/
	
}

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
using std::setfill;
using std::setw;

void Date::print() const
{
    cout << _year << '.' << setfill('0') << setw(2) <<_month 
		<< '.' << setw(2) << _day << endl;
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

ostream& operator << (ostream& s, const Date& d)
{
    s << d._year << '.' << setfill('0') << setw(2) << d._month 
		<< '.' << setw(2) << d._day;
	return s;
}

istream& operator >> (istream& s, Date& d)
{
    int year, month, day;
    char ch = '.';
    s >> year >> ch  >> month >> ch >> day;
    d.set(year, month, day);
	return s;	
}
