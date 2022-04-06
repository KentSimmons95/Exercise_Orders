#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
/*
*
	sort it by name (of customer), and write it back out to a file. Create another
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
	int i;
	vector<Purchase> p;

public:

	Order(string name, string address, int items, vector<Purchase> purchases)
		:n(name), a(address), i(items), p(purchases)
	{
		
	}
	//Default Constructor
	Order() 
	{
		n = "";
		a = "";
		i = 0;
		p = vector<Purchase>();
	}

	//Copy Constructor
	Order(const Order& o1) { n = o1.n; a = o1.a; i = o1.i; p = o1.p; };

	string name() { return n; };
	string address() { return a; };
	int data() { return i; };
	vector<Purchase> purchases() { return p; };

	void export_order(const string& fn);
};

vector<Order> import_orders(const string& fn);
vector<Order> sort_orders(vector<Order>& vo);
void print_orders(vector<Order>& o);
void clean_file(const string& fn);
void file_populate();
void file_populate_vector(vector<Order>& o);