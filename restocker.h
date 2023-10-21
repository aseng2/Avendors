#pragma once
#include <iostream>
#include <string>
using namespace std;

class Restocker
{
private:
	int restcokerId; //globale variable

public:
	Restocker(); // initial state of the restocker
	Restocker(string snakes, int numSnakes);
	void store_new_items(string snakes, int numSnakes); // replace damage and expired items with new items 
	// or jusr remove all items 
	void store_items(string snakes, int numItems); // adding newitems to the vending machine
	void prepare_inventory(string snakes, int numItems);



};


