#include "Date.h"

Date::Date()
{	year = 0;	month = 0;	day = 0;
	hours = 0;	minutes = 0;	seconds = 0;}

Date::Date(time_t tm)
{	struct tm s_t;
	localtime_s(&s_t, &tm);
	year = s_t.tm_year + 1900;
	month = s_t.tm_mon + 1;
	day = s_t.tm_mday;
	hours = s_t.tm_hour;
	minutes = s_t.tm_min;
	seconds = s_t.tm_sec;}

string Date::Time(time_t value)
{	struct tm s_t;
	localtime_s(&s_t, &value);
	int year = s_t.tm_year + 1900;
	int month = s_t.tm_mon + 1;
	int day = s_t.tm_mday;
	int hours = s_t.tm_hour;
	int minutes = s_t.tm_min;
	int seconds = s_t.tm_sec;
	string s = to_string(year) + '/' + to_string(month) + '/' + to_string(day) + '-' 
		+ to_string(hours) + ':' + to_string(minutes) + ':' + to_string(seconds);
	return s;
}

ostream & operator<<(ostream & os, const Date & obj)
{
	os << obj.day << "/" << obj.month << "/" << obj.year << "-" << obj.hours << ":" << obj.minutes << ":" << obj.seconds << " ";
	return os;
}
