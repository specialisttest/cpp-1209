#include <iostream>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Time
{
    int hour;
    int min;
    int sec;
};

void set(Date& date, int year, int month, int day)
{
    if (year >= 1 && year <= 2100)
        date.year = year;
    if (month >= 1 && month <=12)
        date.month = month;
    if (day >= 1 && day <= 31)
        date.day = day;
}
void set(Time& time, int hour, int min, int sec = 0)
{
    if (hour >= 0 && hour <= 23)
        time.hour = hour;
    if (min >= 0 && min <= 59)
        time.min = min;
    if (sec >= 0 && sec <= 59)
        time.sec = sec;
}
void read(Time& time)
{
    cout << "Hour (0-23): ";
    int h;
    cin >> h;
    cout << "Min (0-59): ";
    int m;
    cin >> m;
    set(time, h, m);
}
void read(Date& date)
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
    set(date, year, month, day);
}

void print(const Date& date)
{
    cout << date.year << '.' << date.month << '.' << date.day << endl;
}
void print(const Time& t)
{
    cout << t.hour << ':' << t.min << ':' << t.sec << endl;
}

int main(int argc, char** argv) {
	Time t;
    read(t);
    print(t);

    Date d;
    read(d);
    print(d);
}
