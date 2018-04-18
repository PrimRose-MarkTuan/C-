#include <iostream>
#include <string>
#pragma once

using namespace std;

class Quote
{
public:
	Quote()
	{
		cout << "Quote Constructor." << endl;
	}
	Quote(string const &b, double p) :bookNo(b), price(p)
	{
		cout << "Quote Constructor takint two parameters." << endl;
	}
	Quote(const Quote& q) :bookNo(q.bookNo), price(q.price)
	{
		cout << "Quote Copy Constructor." << endl;
	}
	Quote& operator=(const Quote& q)
	{
		cout << "Quote Copy assignment operator." << endl;
		price = q.price;
		bookNo = q.bookNo;
		return *this;
	}

	string isbn() const
	{
		return bookNo;
	}
	virtual double net_price(size_t n) const
	{
		return n*price;
	}
	virtual void debug() const
	{
		cout << "data members:\n" << "\tbooNo:" << bookNo << "\tprice:" << price << endl;
	}
	virtual ~Quote() = default;

private:
	string bookNo;

protected:
	double price = 0.0;
};

double price_total(ostream &os, Quote const &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
