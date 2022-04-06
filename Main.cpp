#include <iostream>
#include "Order.h"
/* Excercise 9
* 
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
		file_populate();

		
		vector<Order> currentorders = import_orders(filename);
		
		cout << endl << "Printing imported order\n";

		print_orders(currentorders);
	}
	catch (...)
	{
		cout << "Caught unknown exception!\n";
	}
}