#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template<typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)
		return -1;
	if (v1 > v2)
		return 1;
	return 0;
}

template<unsigned N,unsigned M>
int compare(const char(&s1)[N], const char(&s2)[M])
{
	return strcmp(s1, s2);
}
