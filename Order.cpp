#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Order.h"

/*
	Define a mechanism for reading and
	writing Orders to and from a file. Define a mechanism for printing Orders.
	Create a file of at least ten Orders, read it into a vector<Order>, sort
	it by name (of customer), and write it back out to a file. Create another
	file of at least ten Orders of which about a third are the same as in the first
	file, read it into a list<Order>, sort it by address (of customer), and write
	it back out to a file. Merge the two files into a third using std::merge().
*/

//--------Helper Functions------------
ostream& operator<<(ostream& os, Purchase& p)
{
	os << p.item_name() << " " << p.item_price() << " " << p.item_count();
	return os;
}

ostream& operator<<(ostream& os, vector<Purchase> vp)
{
	for (auto& x : vp)
	{
		os << x << " ";
	}
	return os;
}

ostream& operator<<(ostream& os, Order& o)
{
	os << o.name() << " " << o.address() << " " << o.data() << " " << o.purchases() << endl;
	return os;
}

ostream& operator<<(ostream& os, vector<Order>& o)
{
	for (auto& x : o)
	{
		cout << x;
	}
	return os;
}


//--------Order Functions------------

void Order::export_order(const string& fn)
{
	Order* o = this;
	ofstream ofile;
	ofile.open(fn, std::ios_base::app);
	if (ofile.is_open())
	{
		ofile << "NewOrder\n" << *o;
	}
}

//TODO Clean up?
vector<Order> Order::import_orders(const string& fn)
{
	vector<Order> orders;
	string line;

	ifstream ifile{ fn };
	//while (getline(ifile, line))
	while (!ifile.eof())
	{
		const string new_order = "NewOrder";
		string test;
		
		//read into temp variables
		string cust_name, cust_addr, item_name;
		double item_price;
		int cust_items = 0;
		int item_count = 0;
		
		vector<Purchase> cust_purch;
		
		getline(ifile, line);
		istringstream iss(line);

		cout << line << endl;

		if (line != new_order)
		{
			iss >> cust_name >> cust_addr >> cust_items;
			for (int i = 0; i < cust_items; ++i)
			{
				iss >> item_name >> item_price >> item_count;
				Purchase item(item_name, item_price, item_count);
				cust_purch.push_back(item);
			}
			Order current_order(cust_name, cust_addr, cust_items, cust_purch);
			orders.push_back(current_order);
		}
	}
	return orders;
}

void print_orders(vector<Order>& o)
{
	cout << o;
}
