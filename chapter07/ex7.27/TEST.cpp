#include "Screen.h"
using namespace std;

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen.display(std::cout);
	cout << endl;

	return 0;
}
