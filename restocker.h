#pragma once
#include <iostream>
#include <string>
using namespace std;

// testing
class Restocker
{
private:
	int id;

public:
	Restocker(int id);
	Restocker();
	~Restocker();
	void set_id(int id);
	int get_id();
	void display_employee();

};


