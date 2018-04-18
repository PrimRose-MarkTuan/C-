#include <iostream>
#include <string>
#include "Disc_quote.h"
#pragma once

using namespace std;

class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(string const& book, double p, size_t qty, double disc) :Disc_quote(book, p, qty, disc)
	{

	}
	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= quantity)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
	virtual ~Bulk_quote() = default;
};
