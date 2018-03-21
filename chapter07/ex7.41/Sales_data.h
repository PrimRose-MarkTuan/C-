#ifndef CP5_ex7_41_h
#define CP5_ex7_41_h

#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
	friend istream& read(istream &is, Sales_data& item);
	friend ostream& print(ostream &os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

public:
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p)
	{
		cout << "Sales_data(const std::string&, unsigned, double)"<< endl;
	}
	Sales_data() :Sales_data("", 0, 0.0) { }
	Sales_data(const string& s) :Sales_data(s, 0, 0.0) { }
	Sales_data(istream& is) :Sales_data()
	{
		cout << "Sales_data(istream& is)" << endl;
		read(is, *this);
	}
	string isbn()
	{
		return bookNo;
	}
	Sales_data& combine(const Sales_data&);

private:
	inline double avg_price() const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

#endif
