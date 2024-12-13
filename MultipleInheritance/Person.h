#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

using std::string;

class Person {
public:
	string	Name;
	int		Income;  // ����������� ����� ����������
	
	virtual int	TotalIncome() {return Income;}
	
	virtual int getIncome () { return Income; }
	virtual void setIncome (int income) { Income = income; }
};

class Student : public virtual Person {
public:
	string Branch; // �������������
	int	   Income; // ��������� 
	
	int getIncome () override { return Income; }
	void setIncome (int income) override  { Income = income; }
	
	// ����������� ����� + ���������
	int	TotalIncome()
	{ return this->Person::Income + this->Student::Income; }
};

class Worker : public virtual Person {
public:
	string Poistion; // ���������
	int	   Income;	 // ��������

	// ����������� ����� + ��������
	int	TotalIncome()
	{ return this->Person::Income + this->Income; /*this->Worker::Income*/ }
};

class WorkingStudent : public virtual Student, public virtual Worker
{
public:
	// ����������� ����� + ��������� + ��������
	int	TotalIncome()
	{ return this->Student::Income + this->Worker::Income + this->Person::Income; }
	
};


#endif
