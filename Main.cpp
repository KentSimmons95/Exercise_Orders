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
		//Test Data
		//Order 1 - Vegetables
		Purchase veg_item1("Apple", 3.50, 7);
		Purchase veg_item2("Banana", 5.50, 7);
		Purchase veg_item3("Ginger", 1.20, 1);
		Purchase veg_item4("Onion", 2.10, 2);
		Purchase veg_item5("Orange", 7.50, 3);
		vector<Purchase> vegetables;
		vegetables.push_back(veg_item1);
		vegetables.push_back(veg_item2);
		vegetables.push_back(veg_item3);
		vegetables.push_back(veg_item4);
		vegetables.push_back(veg_item5);

		//Order 2 - Meat
		Purchase meat_item1("Steak", 12.50, 1);
		Purchase meat_item2("Ribs", 18.50, 2);
		Purchase meat_item3("Chicken", 8.00, 2);
		vector<Purchase> meat;
		meat.push_back(meat_item1);
		meat.push_back(meat_item2);
		meat.push_back(meat_item3);

		//Oder 3 - Fish
		Purchase fish_item1("Cod", 6.50, 2);
		Purchase fish_item2("Hake", 8.20, 1);
		Purchase fish_item3("Snapper", 5.00, 5);
		Purchase fish_item4("Kingfish", 12.50, 3);
		vector<Purchase> fish;
		fish.push_back(fish_item1);
		fish.push_back(fish_item2);
		fish.push_back(fish_item3);
		fish.push_back(fish_item4);

		//Order 4 Snacks
		Purchase snacks_item1("Chips", 1.50, 8);
		Purchase snacks_item2("Fizzers", .50, 20);
		Purchase snacks_item3("Coke", 3.00, 6);
		Purchase snacks_item4("Crackers", 2.50, 3);
		vector<Purchase> snacks;
		snacks.push_back(snacks_item1);
		snacks.push_back(snacks_item2);
		snacks.push_back(snacks_item3);
		snacks.push_back(snacks_item4);

		//Order 5 Alcohol
		Purchase alcohol_item1("Beer", 2.50f, 6);
		Purchase alcohol_item2("Wine", 14.00, 1);
		Purchase alcohol_item3("Cider", 4.50f, 6);
		Purchase alcohol_item4("Gin", 22.50, 1);
		vector<Purchase> alcohol;
		alcohol.push_back(alcohol_item1);
		alcohol.push_back(alcohol_item2);
		alcohol.push_back(alcohol_item3);
		alcohol.push_back(alcohol_item4);

		Order order1("Kent", "Wellington", 5, vegetables);
		Order order2("Heather", "Waiwhetu", 4, fish);
		Order order3("Merilyn", "Wainui", 4, alcohol);
		Order order4("Adam", "LincolnAve", 3, meat);
		Order order2("Sam", "Avalon", 4, snacks);

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