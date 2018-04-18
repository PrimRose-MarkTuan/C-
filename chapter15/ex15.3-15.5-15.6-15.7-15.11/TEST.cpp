#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

using namespace std;

int main()
{
	cout << "\n===== ex03 =====" << endl;
	Quote quote_03("0-201-78345-X", 23.8);
	price_total(cout, quote_03, 3);

	cout << "\n===== ex05 =====" << endl;
	Bulk_quote bulk_quote("0-201-78345-X", 23.8, 3, 0.5);
	price_total(cout, bulk_quote, 4);

	cout << "\n===== ex07 =====" << endl;
	Limit_quote limit_quote("0-201-78345-X", 23.8, 3, 5, 0.5);
	price_total(cout, limit_quote, 6);

	cout << "\n===== ex11 =====" << endl;
	Quote quote_11("0-201-82470-1", 50);
	Bulk_quote bulk_quote_11("0-201-82470-1", 50, 5, 0.19);
	Limit_quote limit_quote_11("0-201-82470-1", 50, 5, 10, 0.19);
	quote_11.debug();
	bulk_quote_11.debug();
	limit_quote_11.debug();
}
