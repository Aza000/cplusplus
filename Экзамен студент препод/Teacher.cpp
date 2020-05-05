#include "Teacher.h"


Teacher::Teacher(const char * surname, const char * name, int age, const char * gender, const char * kafedra)
{
	strcpy_s(this->surname, surname);
	strcpy_s(this->name, name);
	this->age = age;
	strcpy_s(this->gender, gender);
	strcpy_s(this->kafedra, kafedra);
}

Teacher::Teacher(const Teacher & obj)
{
	strcpy_s(this->surname, obj.surname);
	strcpy_s(this->name, obj.name);
	this->age = obj.age;
	strcpy_s(this->gender, obj.gender);
	strcpy_s(this->kafedra, obj.kafedra);
}

ostream & operator<<(ostream & os, Teacher obj)
{
	os << obj.surname << " " << obj.name << " " << obj.age << " " << obj.gender << " " << obj.kafedra << endl;
return os;
}

bool operator>(Teacher obj1, Teacher obj2)
{
	return obj1.age>obj2.age;
}

bool operator<(Teacher obj1, Teacher obj2)
{
	return obj1.age<obj2.age;
}

bool operator==(Teacher obj1, Teacher obj2)
{
	return (!strcmp(obj1.kafedra,obj2.kafedra));
}

bool operator==(Teacher obj, const char * kafedra)
{
	return (!strcmp(obj.kafedra, kafedra));
}

istream& operator>>(istream& is, Teacher &obj)
{is.ignore();
	is.getline(obj.surname, 50);
	is.getline(obj.name, 50);
	is >> obj.age;
	is >> obj.gender >> obj.kafedra;
	
	return is;
}