#include "Date.h"

int ds[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date Date::operator+(Date d)
{
	Date rez(*this);
	rez.day += d.day;
	rez.month += rez.day / ds[month];
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		ds[2] = 29;
	else
		ds[2] = 28;

	if (rez.day > ds[month])
		rez.day = rez.day % ds[month];

	rez.month = rez.month + d.month;
	if (rez.month > 12)
	{
		rez.year += rez.month / 12;
		rez.month = rez.month % 12;
	}
	rez.year += d.year;
	return rez;
}

Date Date::operator-(Date d)   //нрмхлюер оепбсч дюрс нр брнпни
{     
	
		Date rez(*this);

		if (rez.day < d.day) {
			rez.day += ds[rez.month];
			rez.month--;
		}

		rez.day -= d.day;
		if (rez.month <= d.month) {
			rez.month += 12;
			rez.year--;
		}

		rez.month -= d.month;
		rez.year -= d.year;
		return rez;
}

Date Date::operator-(int days)
{

	Date rez(*this);
	rez.day = rez.day - days;
	while (rez.day < 0) {

		rez.month--;
		if (isLeapYear(rez.year))
			ds[2] = 29;
		else ds[2] = 28;
		if (rez.month == 0)
		{
			rez.month = 12;
			rez.year--;
		}
		rez.day += ds[rez.month];
	}
	return rez;
	
}




Date Date::operator+(int days)
{
	Date rez(*this);
	rez.day += days;

	while (rez.day > ds[rez.month]) {

		if (rez.year % 4 == 0 && rez.year % 100 != 0 || rez.year % 400 == 0)
			ds[2] = 29;
		else
			ds[2] = 28;

		rez.day -= ds[rez.month];
		rez.month++;

		if (rez.month > 12)
		{
			rez.month = 1;
			rez.year++;
		}
	}



	return rez;
}



Date Date::sum_date(Date d)
{
	Date rez(*this);
	rez.day += d.day;
	rez.month += rez.day / ds[month];
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		ds[2] = 29;
	else
		ds[2] = 28;

	if (rez.day > ds[month])
		rez.day = rez.day % ds[month];

	rez.month = rez.month + d.month;
	if (rez.month > 12)
	{
		rez.year += rez.month / 12;
		rez.month = rez.month % 12;
	}
	rez.year += d.year;
	return rez;
}

Date Date::subtrct_date(Date d)//нрмхлюер оепбсч дюрс нр брнпни
{
	Date rez(*this);

	if (rez.day < d.day) {
		rez.day += ds[rez.month];
		rez.month--;
	}

	rez.day -= d.day;
	if (rez.month <= d.month) {
		rez.month += 12;
		rez.year--;
	}

	rez.month -= d.month;
	rez.year -= d.year;
	return rez;
}

Date Date::subtrct_date(int days)
{
	Date rez(*this);
	rez.day = rez.day - days;
	while (rez.day < 0) {

		rez.month--;
		if (isLeapYear(rez.year))
			ds[2] = 29;
		else ds[2] = 28;
		if (rez.month == 0)
		{
			rez.month = 12;
			rez.year--;
		}
		rez.day += ds[rez.month];
	}
	return rez;
}


bool Date::isE(Date d) {
	if (this->day == d.day && this->month == d.month && this->year == d.year)
	{
		return true;
	}

	else 
		return false;
}

Date Date::sum_date(int days)
{
	Date rez(*this);
	rez.day += days;

	while (rez.day > ds[rez.month]) {

		if (rez.year % 4 == 0 && rez.year % 100 != 0 || rez.year % 400 == 0)
			ds[2] = 29;
		else
			ds[2] = 28;

		rez.day -= ds[rez.month];
		rez.month++;

		if (rez.month > 12)
		{
			rez.month = 1;
			rez.year++;
		}
	}



	return rez;
}




void Date::print()
{
	cout << day << "/" << month << "/"<<year << endl;
}

void Date::printAmerican()
{
	cout << month << " " << day << " " << year << endl;
}

bool Date::isEqual(Date d)
{
	return (this->day == d.day
		&& this->month == d.month
		&& this->year == d.year);
}

void Date::enter()
{
	cin >> day >> month >> year;
}

bool isLeapYear(int year)
{
	return (year % 4 ==0 && year % 100 !=0 || year % 400 == 0);
}
