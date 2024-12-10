#ifndef _DATE_H_
#define _DATE_H_

class Date
{
private:
    int _year;
    int _month;
    int _day;
    
    int compareTo(const Date& d) const;
    
public:

    void set(int year = 2000, int month = 1, int day = 1);
    void print() const;
    void read();
    
    bool equals(const Date& d) const { return this->compareTo(d) == 0; } 
    bool greater(const Date& d) const { return this->compareTo(d) > 0; } 
    bool less(const Date& d) const { return this->compareTo(d) < 0; } 

    bool equals(const Date* d) const { return equals(*d); } 
    bool greater(const Date* d) const { return greater(*d); } 
    bool less(const Date* d) const { return less(*d); } 
    
    friend int compareDate(const void* d1, const void* d2);

};

int compareDate(const void* d1, const void* d2);

#endif
