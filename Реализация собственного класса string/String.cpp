#include "String.h"

String::String(const char * str) {
	buf_size = strlen(str) + 1;
	stringRep = new char[buf_size];

	char *tmp = stringRep;
	while (*str != '\0') {
		*tmp = *str;
		tmp++;
		str++;
	}
	*tmp = '\0';
}

String::String(size_t len, char s) {
	buf_size = len + 1;
	stringRep = new char[buf_size];
	for (int i = 0; i < buf_size - 1; i++)
		stringRep[i] = s;
	stringRep[len] = '\0';
}

String::String(size_t len) {
	buf_size = len;
	stringRep = new char[buf_size];
	stringRep[0] = '\0';
}

String::String(const String & obj) {
	this->buf_size = obj.buf_size;
	this->stringRep = new char[buf_size];
	for (int i = 0; i < buf_size; i++) {
		stringRep[i] = obj.stringRep[i];
	}
}

String::~String() {
	delete[] stringRep;
}

size_t String::size()const {
	int k = 0;
	char* tmp = stringRep;
	while (*tmp != '\0')
	{
		k++;
		tmp++;
	}
	return k;
}

const char * String::getStrRep()const {
	return stringRep;
}

char & String::getAt(size_t pos)const {
	return stringRep[pos];
}

String & String::AddCharAt(size_t pos, char c)
{
	size_t str_size = size();
	if (pos <= str_size) {
		if (buf_size <= str_size + 1) {
			buf_size *= 2;
			char* tmp = new char[buf_size];
			for (int i = 0; i < str_size; i++) {
				tmp[i] = stringRep[i];
			}
			delete[] stringRep;
			stringRep = tmp;
		}
		stringRep[str_size] = c;
		for (int i = str_size; i > pos; i--) {
			swap(stringRep[i], stringRep[i - 1]);
		}
		stringRep[str_size + 1] = '\0';
	}
	return(*this);
}

String & String::DelCharAt(size_t pos)
{
	size_t str_size = size();
	if (pos < str_size) {
		for (int i = pos; i < str_size; i++) {
			stringRep[i] = stringRep[i + 1];
		}
	}
	return(*this);
}

String & String::ConcatStr(const String & str)
{
	for (int i = 0; i < str.size()+1; i++) {
		AddCharAt(size(), str.getAt(i));
	}
	return(*this);
}

String & String::ConcatStr(const char * str) {

		for(int i = 0; i < strlen(str); i++) {
		AddCharAt(size(), str[i]);
		}
		return(*this);
}

String & String::operator+(const String & str)
{
	for (int i = 0; i < str.size() + 1; i++) {
		AddCharAt(size(), str.getAt(i));
	}
	return(*this);
}

String String::operator+(const char * str)
{
	for (int i = 0; i < strlen(str); i++) {
		AddCharAt(size(), str[i]);
	}
	return(*this);
}

String String::operator+(const char c)
{
	AddCharAt(size(), c);
	return(*this);
}

String & String::AddStrAt(const String & str, size_t pos)
{
	size_t str_size = str.size();

	for (int i = str_size -1; i >= 0; i--) {
		AddCharAt(pos, str.getAt(i));
	}

	return(*this);
}

String & String::AddStrAt(const char * str, size_t pos)
{
	size_t str_size = strlen(str);

	for (int i = str_size - 1; i >= 0; i--) {
		AddCharAt(pos, str[i]);
	}

	return(*this);
}

String & String::DelStrAt(size_t beg, size_t end) {
	for (int i = beg; i <= end; i++) {
		DelCharAt(beg);
	}
	return(*this);
}

int String::SubStr(const String & what)
{
	int rez = -1;
	if (strstr(getStrRep(), what.getStrRep()))
	rez = (strstr(getStrRep(), what.getStrRep()) - getStrRep());
	return rez;
}

String & String::Replace(const char * what, const char * rep)
{
	int k = 0;
	while (true) {
		k = SubStr(what);
			if (k == -1) break;
		DelStrAt(k, k + strlen(what) - 1);
		AddStrAt(rep, k);
	}
	return(*this);
}

String & String::Replace(const String & what, const String & rep)
{
	int k = 0;
	//while (true);
	while (k != -1) {
		k = SubStr(what);
		//if(k == -1)break;
		DelStrAt(k, k+ what.size() - 1);
		AddStrAt(rep, k);
	}
	return(*this);
}

char * String::GetRange(size_t beg, size_t end)
{
	char *tmp = new char[end - beg + 1];
	int index = 0;
	for (int i = beg; i <= end; i++) {
		tmp[index] = stringRep[i];
		index++;
	}
	tmp[index] = '\0';
	return tmp;
}

String String::Format(const char * specs, ...)
{
	String obj;
	va_list ap;
	int var;
	double d;
	char buf[20];
	__crt_va_start(ap, specs);
	while (*specs != '\0') {
		if (*specs == 'i') {
			var = __crt_va_arg(ap, int);
			_itoa_s(var, buf, 10);
			obj.ConcatStr(buf);
		}
		else if (*specs == 'c') {
			char c = __crt_va_arg(ap, char);
			obj.AddCharAt(obj.size(), c);
		}
		else if (*specs == 'd') {
			d = __crt_va_arg(ap, double);
			sprintf_s(buf, "%.2f", d);
			obj.ConcatStr(buf);
		}
		specs++;
	}
	return obj;
}

ostream& operator<<(ostream& os, const String obj) {
	os << obj.stringRep;
	return os;
}
