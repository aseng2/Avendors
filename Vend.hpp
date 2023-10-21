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



class Vend
{
public:
	Vend(); // Constructor
	void Customer_Request();
	void VendItem();
//	void Notification(); ADD LATER

private:
	std::string RequestNum; // the number the customer inputs to choose a snack.
	double MoneyIn; // tracks how much total money is in the machine
	double Sales = 0; // tracks the amount of money made from sales
	int salesTracker; // tracks the number of sold items
	char ValidInput;

	void checkInventory();
	void checkRecall();
};