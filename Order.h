#pragma once
#include <string>
#include <vector>
/*
*
	Define a mechanism for reading and
	writing Orders to and from a file. Define a mechanism for printing Orders.
	Create a file of at least ten Orders, read it into a vector<Order>, sort
	it by name (of customer), and write it back out to a file. Create another
	file of at least ten Orders of which about a third are the same as in the first
	file, read it into a list<Order>, sort it by address (of customer), and write
	it back out to a file. Merge the two files into a third using std::merge().
*
*/
using namespace std;


class Purchase {
	string n;
	double p;
	int c;

public:

	Purchase(string item_name, double item_price, int item_count)
		:n(item_name), p(item_price), c(item_count)
	{

	}

	string item_name() { return n; };
	double item_price() { return p; };
	int item_count() { return c; };
};

class Order {
	string n;
	string a;
	string d;
	vector<Purchase> p;

public:

	Order(string name, string address, string data, vector<Purchase> purchases)
		:n(name), a(address), d(data), p(purchases)
	{

	}

	string name() { return n; };
	string address() { return a; };
	string data() { return d; };
	vector<Purchase> purchases() { return p; };
};