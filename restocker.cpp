#include "restocker.h"
// testing



Restocker::Restocker()
{
	name = " ";
}

//Restocker::Restocker(string name)
//{
	//this->name = name;
//}

Restocker::~Restocker()
{

}


void Restocker::set_restocker_name(string name)
{
	this->name = name;
}


string Restocker::get_restocker_name()
{
	return name;
}


void Restocker::restock(Snack snack)
{
	Inventory restockInv;
	restockInv.RestockInventory(snack);
}




//void Restocker::display_employee()
//{
	//cout << " employee ID:";
	//cout << name << endl;
//}