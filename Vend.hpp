/*#pragma once
#include <iostream>
#include <string>
#include "Management.hpp"
#include "Vend.cpp"

using namespace std;

class Vend
{
	char RequestNum; // the number the customer inputs to choose a snack.
	double MoneyIn; //tracks how much total money is in the machine
	double Sales = 0; //tracks amount of money made from sales
	int snackTracker; //tracks number of sold items
	char ValidInput;
	
	void checkInventory() //checks the item requested by Customer_Request against the machine inventory to see if the item is out of stock or expired.
	{

	}
	void Customer_Request()
	{

	}
	void CheckRecall()
	{

	}
	void VendItem()
	{

	}
	void Notification() //sends a notification to management if out of stock or expired items are being requested.
	{

	}

}; */

#pragma once
#include <iostream>
#include <string>
#include "Management.hpp"
#include "Inventory.hpp"
#include "restocker.h"
#include "sstream"



class Vend: public Restocker
{
public:
	Vend(int CurrentDate); // Constructor
	void Customer_Request(Inventory List);
	void VendItem();
//	void Notification(); ADD LATER

private:
	int CurrentDate;
	std::string RequestNum; // the number the customer inputs to choose a snack.
	Snack Item;
	Inventory Stuff;
	double MoneyIn; // tracks how much total money is in the machine
	double Sales = 0; // tracks the amount of money made from sales
	double CustomerMoney;
	char ValidInput;
	std::string RestockCode = "AA11";  //code to access restock
	std::string CustomerInput; 
	std::string ExitCode;

	void checkInventory(Inventory List);
	void checkRecall();
	void restockProcess();
	void Menu();
	void SaleProcess();
};