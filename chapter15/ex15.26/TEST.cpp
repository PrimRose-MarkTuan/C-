#include "Quote.h"
#include "Bulk_quote.h"

int main()
{
	cout << "\n===== ex26 =====" << endl;
	Quote quote_26;
	Quote quote_26_p("0-201-78345-X", 23.8);
	Quote quote_26_cp(quote_26_p);
	Quote quote_26_mv(std::move(quote_26_p));

	cout << "------ISBN: price------" << endl;
	cout << quote_26.isbn() << ": " << quote_26.net_price(3) << endl;
	cout << quote_26_cp.isbn() << ": " << quote_26_cp.net_price(3) << endl;
	cout << quote_26_mv.isbn() << ": " << quote_26_mv.net_price(3) << endl;
	cout << "-----------------------" << endl;

	Bulk_quote bulk_26;
	Bulk_quote bulk_26_p("0-201-78345-X", 23.8, 3, 0.5);
	Bulk_quote bulk_26_cp(bulk_26_p);
	Bulk_quote bulk_26_mv(std::move(bulk_26_p));

	cout << "------ISBN: price------" << endl;
	cout << bulk_26.isbn() << ": " << bulk_26.net_price(3) << endl;
	cout << bulk_26_cp.isbn() << ": " << bulk_26_cp.net_price(3) << endl;
	cout << bulk_26_mv.isbn() << ": " << bulk_26_mv.net_price(3) << endl;
	cout << "-----------------------" << endl;
}
