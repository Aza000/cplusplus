#include "Catalog.h"

void Catalog::push(Product el)
{	ps.push_back(el);}

Product Catalog::pop()
{	Product tmp = ps.back();
	ps.pop_back();
	return tmp;}

int Catalog::size()
{	return ps.size();}

Product & Catalog::operator[](int index)
{	if (index < 0 || index >= size())
		throw "out of range";

	return ps[index];}

int Catalog::find(const char * title)
{
	for (int i = 0; i < ps.size(); i++) {
		if (ps[i].getTitle() == string(title))
			return i;
	}
	return -1;
}

