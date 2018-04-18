#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

using namespace std;

int main()
{
	cout << "\n===== ex15 =====" << endl;

	Bulk_quote bulk_quote_15("0-201-82470-1", 50, 5, 0.19);
	price_total(cout, bulk_quote_15, 6);

	cout << "\n===== ex16 =====" << endl;

	Limit_quote limit_quote_16("0-201-82470-1", 50, 5, 10, .19);
	price_total(cout, limit_quote_16, 14);
}
