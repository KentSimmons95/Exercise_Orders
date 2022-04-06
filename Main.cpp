#include <iostream>
#include "Order.h"

/*
	Go back to page 800 for other questions
*/

using namespace std;

int main()
{
	try
	{
		const string orders_file = "orders.txt";
		//setup file with data
		file_populate();
		//import orders back for sorting
		vector<Order> currentorders = import_orders(orders_file);
		sort_orders(currentorders);
		//print sorted vector
		cout << endl << "Printing sorted orders\n";
		print_orders(currentorders);
		//reset file before pushing sorted vector
		clean_file(orders_file);
		file_populate_vector(currentorders);
	}
	catch (...)
	{
		cout << "Caught unknown exception!\n";
	}
}