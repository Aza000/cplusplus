#include "Student.h"

Student::Student()
{
	strcpy_s(this->name, "");
	strcpy_s(this->surname, "");
	this->age = 0;
	strcpy_s(this->gender, "");
	strcpy_s(group, "");
}

Student::Student(const char * surname, const char * name, int age, const char * gender, const char * group)
{
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);
	this->age = age;
	strcpy_s(this->gender, gender);
	strcpy_s(this->group, group);
}

Student::Student(const Student & obj)
{
	strcpy_s(this->name , obj.name);
	strcpy_s(this->surname, obj.surname);
	this->age = obj.age;
	strcpy_s(this->gender, obj.gender);
	strcpy_s(this->group, obj.group);


}

ostream & operator<<(ostream & os, Student obj)
{
	os << obj.surname << " " << obj.name << " " << obj.age << " " << obj.group << " " << obj.gender<<endl;
	return os;
}

bool operator!=(Student obj, const char * gender)
{
	return strcmp(obj.gender, gender);
}

bool operator==(Student obj, const char * group)
{
	return (!strcmp(obj.group,group));
}

bool operator==(Student obj1, Student obj2)
{
	return strcmp(obj1.group, obj2.group);
}

istream & operator>>(istream & is, Student & obj)
{is.ignore();
	is.getline(obj.surname, 50);
	is.getline(obj.name, 50);
	is >> obj.age;
	is >> obj.gender >> obj.group;
	
	return is;
}
