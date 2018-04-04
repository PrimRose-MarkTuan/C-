#include "12-2.h"
#include <iostream>

using namespace std;

int main()
{
	const StrBlob csb{ "Mark", "Tuan", "19930904" };
	StrBlob sb{ "Rose", "Tuan", "19940310" };
	cout << csb.front() << " " << csb.back() << endl;
	sb.back() = "19930904";
	cout << sb.front() << " " << sb.back() << endl;
	return 0;
}
