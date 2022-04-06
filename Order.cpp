#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Order.h"

/*
	sort it by name (of customer), and write it back out to a file. Create another
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

vector<Order> import_orders(const string& fn)
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

vector<Order> sort_orders(vector<Order>& vo)
{
	Order temp;
	for (int i = 0; i < vo.size(); ++i)
	{
		for (int j = 0; j < vo.size(); ++j)
		{
			if (vo[i].name() < vo[j].name())
			{
				temp = vo[j];
				vo[j] = vo[i];
				vo[i] = temp;
			}
		}
	}
	return vo;
}

void print_orders(vector<Order>& o)
{
	cout << o;
}

//Quick file cleanup between operations
void clean_file(const string& fn)
{
	ofstream ofs;
	ofs.open(fn, ofstream::out, ofstream::trunc);
	ofs.close();
}

//File setup 
void file_populate()
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

	//Order 6 Baking
	Purchase baking_item1("Flour", 3.00, 1);
	Purchase baking_item2("Cheese", 14.00, 1);
	Purchase baking_item3("Milk", 1.50f, 1);
	Purchase baking_item4("Eggs", 4.00f, 6);
	Purchase baking_item5("Bicarb", 5.00, 1);
	Purchase baking_item6("Yeast", 4.50, 2);
	vector<Purchase> baking;
	baking.push_back(baking_item1);
	baking.push_back(baking_item2);
	baking.push_back(baking_item3);
	baking.push_back(baking_item4);
	baking.push_back(baking_item5);
	baking.push_back(baking_item6);

	//Order 6 Garden
	Purchase garden_item1("Hoe", 25.00, 1);
	Purchase garden_item2("LawnMower", 250.00, 1);
	vector<Purchase> garden;
	garden.push_back(garden_item1);
	garden.push_back(garden_item2);

	//Assign orders
	Order order1("Kent", "Wellington", 5, vegetables);
	Order order2("Heather", "Waiwhetu", 4, fish);
	Order order3("Merilyn", "Wainui", 4, alcohol);
	Order order4("Adam", "LincolnAve", 3, meat);
	Order order5("Sam", "Avalon", 4, snacks);
	Order order6("Scott", "Wellington", 6, baking);
	Order order7("Gina", "Wainui", 2, garden);

	//Add orders to vector
	vector<Order> orders;
	orders.push_back(order1);
	orders.push_back(order2);
	orders.push_back(order3);
	orders.push_back(order4);
	orders.push_back(order5);
	orders.push_back(order6);
	orders.push_back(order7);

	for (auto& x : orders)
	{
		x.export_order(filename);
	}
}

void file_populate_vector(vector<Order>& o)
{
	const string filename = "orders.txt";

	for (auto& x : o)
	{
		x.export_order(filename);
	}
}
