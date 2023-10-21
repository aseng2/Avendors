#include "restocker.h"
// testing



Restocker::Restocker()
{
	id = 0;
}

Restocker::Restocker(int id)
{
	this->id = id;
}

Restocker::~Restocker()
{

}


void Restocker::set_id(int id)
{
	this->id = id;
}


int Restocker::get_id()
{
	return id;
}

void Restocker::display_employee()
{
	cout << " employee ID:";
	cout << id << endl;
}