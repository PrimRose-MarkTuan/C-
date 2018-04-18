#include <iostream>
#include <string>
#include "Quote.h"
#pragma once

using namespace std;

class Bulk_quote :public Quote
{
public:
	Bulk_quote()
	{
		cout << "Bulk_quote Constructor." << endl;
	}
	Bulk_quote(string const& book, double p, size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc)
	{
		cout << "Bulk_quote Constructor taking four parameters." << endl;
	}
	Bulk_quote(const Bulk_quote &rhs) :Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount)
	{
		cout << "Bulk_quote Copy Constructor." << endl;
	}
	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		cout << "Bulk_quote Copy assignment operator." << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}
	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
	virtual void debug() const override 
	{
		Quote::debug();
		cout << "\tminqty: " << min_qty << "\tdiscount: " << discount << endl;
	}
	virtual ~Bulk_quote() = default;

protected:
	size_t min_qty = 0;
	double discount = 0.0;
};
