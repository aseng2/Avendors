#pragma once
#include <iostream>
#include <string>

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
		cout << "Welcome! Please Enter Your Snack Request: ";
		cin >> RequestNum;
		if (RequestNum == (ValidInput))
		{
			cout << "Vending snack!" << endl;
			VendItem(/*RequestNum*/);
		}
		else
		{
			cout << "This item is either out of stock, expired, or has been recalled" << endl;
		}


			
	}
	void VendItem()
	{
		Sales = Sales + 4; /*REPLACE WITH PRICE VARIABLE FROM INVENTORY*/
		snackTracker = snackTracker + 1;
	}
	void Notification() //sends a notification to management if out of stock or expired items are being requested.
	{

	}

};