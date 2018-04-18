#include "Base.h"

using namespace std;

int main()
{
	cout << "\n===== ex20 =====" << endl;
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;

	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	p = &d2; // error: inaccessible
	p = &d3; // error: inaccessible
	p = &dd1;
	p = &dd2; // error: inaccessible
	p = &dd3; // error: inaccessible
}
