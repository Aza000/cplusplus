#include "Product.h"

Product::Product()
{	title = "";
	price = 0;
	amount = 0;}

Product::Product(string title, double price, int amount)
{	this->title = title;
	this->price = price;
	this->amount = amount;}

int & Product::getAmount()
{
	return amount;
}

string Product::getTitle()
{
	return title;
}

bool Product::operator<(const Product & obj) const
{	return price<obj.price;}

double Product::getPrice()
{
	return price;
}

ostream & operator<<(ostream & os, const Product & obj)
{	os << obj.title << " " << obj.price << " " << obj.amount<<" ";
	return os;}

istream& operator>>(istream& is, Product& obj) {
	is >> obj.title >> obj.price >> obj.amount;
	return is;
}