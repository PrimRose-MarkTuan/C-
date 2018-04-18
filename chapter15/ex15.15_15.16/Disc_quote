#include "Quote.h"
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Disc_quote:public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(string const &b, double p, size_t q, double d) :Quote(b, p), quantity(q), discount(d)
	{

	}
	virtual double net_price(size_t) const = 0;
	virtual ~Disc_quote() = default;

protected:
	size_t quantity = 0;
	double discount = 0.0;
};
