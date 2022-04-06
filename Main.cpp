#include <iostream>
#include "Order.h"
/* Excercise 9
* 
	sort it by name (of customer), and write it back out to a file. Create another
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