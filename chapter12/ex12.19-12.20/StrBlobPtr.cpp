#include <iostream>
#include "12-19.h"
#include <fstream>

using namespace std;

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

int main()
{
	ifstream ifs("book.txt");
	StrBlob blob;
	for (string str; getline(ifs, str);)
		blob.push_back(str);
	for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;
}
