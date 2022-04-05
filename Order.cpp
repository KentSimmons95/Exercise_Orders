#include <vector>
#include <iostream>
#include <fstream>
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
	os << "#" << p.item_name() << " " << p.item_price() << " " << p.item_count();
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
	os << "%" << o.name() << " " << o.address() << " " << o.data() << " " << o.purchases() << endl;
	return os;
}

//--------Order Functions------------
void Order::export_order(const string& fn)
{
	Order* o = this;
	ofstream ofile{ fn };
	if (ofile.is_open())
	{
		ofile << *o;
	}
}
