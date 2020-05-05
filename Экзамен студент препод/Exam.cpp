#include "Exam.h"
/*1. ���������� ������� ����� ��������
������� ������ ��������� ��������� ����:
�) �������
�) ���
�) �������
�) ���
�) ������
������� ������ ��������� ��������� ������:
� ����������� �� ���������;
� ����������� � �����������;
� ����������� �����������;
� ����������;
*/



Exam::Exam(const char * subject, Student sobj,Teacher tobj, int grade)
{
	strcpy_s(this->subject, subject);
	strcpy_s(this->student_surname, sobj.surname);
	strcpy_s(this->teacher_surname, tobj.surname);
	this->grade = grade;
}

Exam Exam::create_exam(const char * subject, Student sobj, Teacher tobj, int grade)
{
	strcpy_s(this->subject, subject);
	strcpy_s(this->student_surname, sobj.surname);
	strcpy_s(this->teacher_surname, tobj.surname);
	this->grade = grade;
	return (*this);
}

bool Exam::operator==(int n)
{
	return (grade==n);
}

bool Exam::operator<=(int n)
{
	return (grade<=n);
}

ostream & operator<<(ostream & os, Exam obj)
{
	os << obj.student_surname << " " << obj.subject << " " << obj.teacher_surname << " " << obj.grade << endl;
	return os;
}
