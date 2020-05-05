#include "Var.h"

Var::Var()
{
	this->intproperty = 0;
	type = INT;
}

Var::Var(int intproperty)
{
	this->intproperty = intproperty;
	type = INT;
}

Var::Var(double doubleproperty)
{
	this->doubleproperty = doubleproperty;
	type = DOUBLE;
}

Var::Var(string stringProperty)
{
	this->stringProperty = stringProperty;
	type = STRING;
}

Var::Var(const char* stringProperty)
{
	this->stringProperty = string(stringProperty);
	type = STRING;
}

Var::operator double()
{
	if (type == INT)
		return intproperty;
	else if (type == DOUBLE)
		return doubleproperty;
}

Var Var::operator+(const Var& obj)
{
	Var rez(*this);
	if (rez.type == STRING) {
		string s;
		if (obj.type == STRING) {
			s = (obj.stringProperty);
		}
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else s = to_string(obj.doubleproperty);
		rez.stringProperty += s;
		}
	else if (rez.type == INT) {
		double d;
		if (obj.type == STRING) {
			d = atof(obj.stringProperty.c_str());
		}
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.type = DOUBLE;
		rez.doubleproperty = rez.intproperty + d;
	}
	else if (rez.type == DOUBLE) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.doubleproperty = rez.doubleproperty + d;
	}
	return rez;
	}

Var Var::operator-(const Var& obj)
{

	Var rez(*this);
	if (rez.type == STRING) {
		string s;
		if (obj.type == STRING)
			s = obj.stringProperty;
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else s = to_string(obj.doubleproperty);
		bool flag;
		rez.stringProperty.clear();
		for (int i = 0; i < this->stringProperty.length(); i++)
		{
			flag = false;
			for (int j = 0; j < s.length(); j++)
			{

				if (this->stringProperty[i] == s[j]) {
					flag = true;
					break;
				}
			}
			if (flag == false)
				rez.stringProperty.push_back(this->stringProperty[i]);
		}
	}

	else if (rez.type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.type = DOUBLE;
		rez.doubleproperty = rez.intproperty - d;
	}
	else if (rez.type == DOUBLE) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.doubleproperty = rez.doubleproperty - d;
	}
	return rez;
}

Var Var::operator*(const Var& obj)
{
	Var rez(*this);
	if (rez.type == STRING) {
		string s;
		if (obj.type == STRING)
			s = obj.stringProperty;
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else s = to_string(obj.doubleproperty);
		bool flag;
		rez.stringProperty.clear();
		for (int i = 0; i < this->stringProperty.length(); i++)
		{
			flag = false;
			for (int j = 0; j < s.length(); j++)
			{

				if (this->stringProperty[i] == s[j]) {
					flag = true;
					break;
				}
			}
			if (flag == true)
				rez.stringProperty.push_back(this->stringProperty[i]);
		}
	}

	else if (rez.type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.type = DOUBLE;
		rez.doubleproperty = rez.intproperty * d;
	}
	else if (rez.type == DOUBLE) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.doubleproperty = rez.doubleproperty * d;
	}
	return rez;
}

Var Var::operator*=(const Var& obj)
{
	(*this) = (*this) * obj;
	return* this;
}

Var Var::operator/(const Var& obj)
{
	Var rez(*this);
	if (rez.type == STRING) {
		string s;
		if (obj.type == STRING)
			s = obj.stringProperty;
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else
			s = to_string(obj.doubleproperty);
		bool flag;
		rez.stringProperty.clear();
		for (int i = 0; i < this->stringProperty.length(); i++)
		{
			flag = false;
			for (int j = 0; j < s.length(); j++)
			{
				if (this->stringProperty[i] == s[j])
				{
					flag = true;
					break;
				}
			}
			if (flag == false)
				rez.stringProperty.push_back(this->stringProperty[i]);
		}

      }
	else if (rez.type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		rez.type = DOUBLE;
		if (d == 0)throw("na nol delit nelzia");
		rez.doubleproperty = rez.intproperty / d;
	
	}
	else if (rez.type == DOUBLE) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		if (d == 0)throw("na nol delit nelzia");
		rez.doubleproperty = rez.doubleproperty / d;

	}
	return rez;
}

Var Var::operator/=(const Var& obj)
{
	(*this) = (*this) / obj;
	return (*this);
}


bool Var::operator<(const Var& obj)
{
	if (type == STRING) {
		string a;
		if (obj.type == STRING)
			a = obj.stringProperty;
		else if (obj.type == INT)
			a = to_string(obj.intproperty);
		else a = to_string(obj.doubleproperty);
		return (a < stringProperty);
	}
	else if (type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return(intproperty<d);
	}
	else {
		double d;
		if (obj.type == STRING) {
			double d;
			d = atof(obj.stringProperty.c_str());
		}
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return(doubleproperty<d);
	}

}

bool Var::operator<=(const Var& obj)
{
	if (type == STRING) {
		string s;
		if (obj.type == STRING)
			s = obj.stringProperty;
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else s = to_string(obj.doubleproperty);
		return (s<=stringProperty);
	}
	else if (type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT) {
			d = obj.intproperty;

		}
		else d = obj.doubleproperty;
		
		return (intproperty <= d);
	}
	else if (type == DOUBLE)
	{
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return (doubleproperty <= d);
	}
}

bool Var::operator>(const Var& obj)
{
	if (type == STRING) {
		string s;
		if (obj.type == STRING)
			s = obj.stringProperty;
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else s = to_string(obj.doubleproperty);
		return (s > stringProperty);
	}
	else if (type == INT)
	{
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return (intproperty > d);
	}
	else if (type == DOUBLE)
	{
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return (doubleproperty > d);
	}
}

bool Var::operator>=(const Var& obj)
{
	if (type == STRING) {
		string s;
		if (obj.type == STRING)
			s = obj.stringProperty;
		else if (obj.type == INT)
			s = to_string(obj.intproperty);
		else s = to_string(obj.doubleproperty);
		return (s >= stringProperty);
	}
	else if (type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT) {
			d = obj.intproperty;

		}
		else d = obj.doubleproperty;

		return (intproperty >= d);
	}
	else if (type == DOUBLE)
	{
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return (doubleproperty >= d);
	}
}



bool Var::operator==(const Var& obj)
{
	if (type == STRING) {
		string a;
		if (obj.type == STRING)
			a = obj.stringProperty;
		else if (obj.type == INT)
			a = to_string(obj.intproperty);
		else a = to_string(obj.doubleproperty);
		return (a == stringProperty);
	}
	else if (type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return(d == intproperty);
	}
	else {
		double d;
		if (obj.type == STRING) {
			double d;
			d = atof(obj.stringProperty.c_str());
		}
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return(d == doubleproperty);
	}
}

bool Var::operator!=(const Var& obj)
{
	if (type == STRING) {
		string a;
		if (obj.type == STRING)
			a = obj.stringProperty;
		else if (obj.type == INT)
			a = to_string(obj.intproperty);
		else a = to_string(obj.doubleproperty);
		return (a != stringProperty);
	}
	else if (type == INT) {
		double d;
		if (obj.type == STRING)
			d = atof(obj.stringProperty.c_str());
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return(d != intproperty);
	}
	else {
		double d;
		if (obj.type == STRING) {
			double d;
			d = atof(obj.stringProperty.c_str());
		}
		else if (obj.type == INT)
			d = obj.intproperty;
		else d = obj.doubleproperty;
		return(d != doubleproperty);
	}
}

Var Var::operator+=(const Var& obj)
{
	(*this) = (*this) + obj;
	return *this;
}

Var Var::operator-=(const Var& obj)
{
	(*this) = (*this) - obj;
	return *this;
}



ostream& operator<<(ostream& os, const Var& obj)
{
	if (obj.type == INT)
	{
		os << obj.intproperty;
	}
	else if (obj.type == DOUBLE)
	{
		os << obj.doubleproperty;
	}
	else 
	{
		os << obj.stringProperty;
	}
	return os;
}

istream& operator>>(istream& is, Var& obj)
{
	if (obj.type == INT)
		is >> obj.intproperty;
	else if (obj.type == DOUBLE)
		is >> obj.doubleproperty;
	else is >> obj.stringProperty;
	return is;
}
