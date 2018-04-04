#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>
#include <string>
#include <exception>

using namespace std;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) { }
	StrBlob(initializer_list<string> l1) :data(make_shared<vector<string>>(l1)) { }
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	string &front()
	{
		check(0, "front on empty StrBlob!");
		return data->front();
	}
	string &back()
	{
		check(0, "back on empty StrBlob!");
		return data->back();
	}
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob!");
		return data->pop_back();
	}
	const string &front() const
	{
		check(0, "front on empty StrBlob!");
		return data->front();
	}
	const string &back() const
	{
		check(0, "back on empty StrBlob!");
		return data->back();
	}

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const
	{
		if (i >= data->size())
			throw out_of_range(msg);
	}
};
