#include <iostream>
#include "Order.h"
/* Excercise 9
* 
	Define an Order class with (customer) name, address, data, and
	vector<Purchase> members. Purchase is a class with a (product) name,
	unit_price, and count members. Define a mechanism for reading and
	writing Orders to and from a file. Define a mechanism for printing Orders.
	Create a file of at least ten Orders, read it into a vector<Order>, sort
	it by name (of customer), and write it back out to a file. Create another
	file of at least ten Orders of which about a third are the same as in the first
	file, read it into a list<Order>, sort it by address (of customer), and write
	it back out to a file. Merge the two files into a third using std::merge().
* 
*/

using namespace std;

int main()
{
	try
	{
		const string filename = "orders.txt";
		//Test Data
		Purchase item1("Apple", 3.50, 7);
		Purchase item2("Banana", 5.50, 7);
		Purchase item3("Ginger", 1.20, 1);
		Purchase item4("Onion", 2.10, 2);
		Purchase item5("Orange", 7.50, 3);

		vector<Purchase> vegetables;
		vegetables.push_back(item1);
		vegetables.push_back(item2);
		vegetables.push_back(item3);
		vegetables.push_back(item4);
		vegetables.push_back(item5);

		Order order1("Kent", "Wellington", 5, vegetables);
		order1.export_order(filename);

		vector<Order> currentorders = order1.import_orders(filename);
		
		cout << endl << "Printing imported order\n";

		print_orders(currentorders);
	}

	catch (...)
	{
		cout << "Cought unknown exception!\n";
	}
}