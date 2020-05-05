#include "Bid.h"

Bid::Bid()
{
	player = "";
	product_title = "";
	bid_price = 0;
	amount = 0;
	raw_time = time(NULL);
	bid_time=Date(raw_time);
}

Bid::Bid(string player, string product_title, double bid_price, 
	int amount, time_t bid_time)
{
	this->player = player;
	this->raw_time = bid_time;
	this->bid_time = Date(bid_time);
	this->product_title = product_title;
	this->bid_price = bid_price;
	this->amount = amount;
}

int Bid::getAmount()const
{
	return amount;
}

int Bid::getBid_Price() const
{
	return bid_price;
}

string Bid::getProductTitle()const
{
	return product_title;
}

bool Bid::operator<(const Bid& obj) const {
	if (bid_price == obj.bid_price)
		return (this->raw_time > obj.raw_time);
	else 
	return (bid_price < obj.bid_price);
}

void Bid::setAmount(int value)
{
	this->amount = value;
}

ostream & operator<<(ostream & os, const Bid & obj)
{
	
	os << obj.player<<" "<<obj.product_title << " " << obj.bid_price
		<< " " << obj.amount << " " << obj.bid_time << " ";
	return os;
}

istream& operator>>(istream& is, Bid& obj) {
	is >> obj.player>>obj.product_title >> obj.bid_price >> obj.amount;
	return is;
}