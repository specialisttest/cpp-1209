#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

using std::string;

class Person {
public:
	string	Name;
	int		Income;  // безусловный доход гражданина
	
	virtual int	TotalIncome() {return Income;}
	
	virtual int getIncome () { return Income; }
	virtual void setIncome (int income) { Income = income; }
};

class Student : public virtual Person {
public:
	string Branch; // специальность
	int	   Income; // стипендия 
	
	int getIncome () override { return Income; }
	void setIncome (int income) override  { Income = income; }
	
	// безусловный доход + стипендия
	int	TotalIncome()
	{ return this->Person::Income + this->Student::Income; }
};

class Worker : public virtual Person {
public:
	string Poistion; // должность
	int	   Income;	 // зарплата

	// безусловный доход + зарплата
	int	TotalIncome()
	{ return this->Person::Income + this->Income; /*this->Worker::Income*/ }
};

class WorkingStudent : public virtual Student, public virtual Worker
{
public:
	// безусловный доход + стипендия + зарплата
	int	TotalIncome()
	{ return this->Student::Income + this->Worker::Income + this->Person::Income; }
	
};


#endif
