#include <iostream>
#include <string>
#include "Disc_quote.h"
#pragma once

using namespace std;

class Limit_quote:public Disc_quote
{
public:
	Limit_quote() = default;
	Limit_quote(const string &b, double p, size_t min, size_t max, double dist) :Disc_quote(b, p, min, dist), max_qty(max)
	{

	}
	double net_price(size_t cnt) const override
	{
		if (cnt > max_qty)
			return max_qty*(1 - discount)*price + (cnt - max_qty)*price;
		else if (cnt >= quantity)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
	~Limit_quote() = default;

private:
	size_t max_qty = 0;
};
