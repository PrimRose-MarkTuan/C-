#include <iostream>
#include <string>
#include "Quote.h"
#pragma once

using namespace std;

class Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(string const& book, double p, size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc)
	{

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
