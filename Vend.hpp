
#pragma once
#include <iostream>
#include <string>
#include "Inventory.hpp"
#include "restocker.h"
#include "sstream"
#include "Management.hpp"



class Vend : public Restocker		//trying removing restocker inheritance
{
public:
	Vend(int CurrentDate); // Constructor
	//void Customer_Request(Inventory List);
	//void VendItem();
	void Menu();
	void setCurrentDate(int NewDate);
	int getCurrentDate();
//	void Notification(); ADD LATER

private:
	int CurrentDate;
	std::string RequestNum; // the number the customer inputs to choose a snack.
	Snack Item;
	Inventory Stuff;
	double MoneyIn = 0; // tracks how much total money is in the machine
	double Sales = 0; // tracks the amount of money made from sales
	double CustomerMoney = 0;
	//char ValidInput;
	std::string RestockCode = "AA11";  //code to access restock
	std::string CustomerInput; 
	std::string ExitCode = "BB22";

	void checkInventory(Inventory List);
	//void checkRecall();
	//void restockProcess();

	void SaleProcess();
};