#pragma once
#include <iostream>
#include <string>
#include "Snack.hpp"
#include "Inventory.hpp"
using namespace std;

// testing
class Restocker: public Inventory
{
private:
	string name;

public:
	//Restocker(string name);
	Restocker();
	~Restocker();
	void set_restocker_name(string name);
	string get_restocker_name();
	void restock(Snack snake);
	//snack_expired(Snake snake);

	//void display_employee();

};


