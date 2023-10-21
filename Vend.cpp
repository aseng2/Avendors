#pragma once
#include <iostream>
#include <string>
#include "Management.hpp"
#include "Management.cpp"
#include "Vend.hpp"

using namespace std;

Vend::Vend() 
{
    // Constructor implementation
    // Initialize member variables if needed
}

void Vend::Customer_Request() 
{
	cout << "Welcome! Please Enter Your Snack Request: ";
	cin >> RequestNum;

	//for management false means it is recalled
	/*Recall(snack object)
		if (false)
		{
			cout << "This object has been recalled"
		}
		else
		//vend function
*/
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

void Vend::VendItem() 
{
	Sales = Sales + 4; /*REPLACE WITH PRICE VARIABLE FROM INVENTORY*/
	snackTracker = snackTracker + 1;
}

void Vend::Notification() 
{
    // Implementation of Notification function
    // ...
}

void Vend::checkInventory() 
{
    // Implementation of checkInventory function
    // ...
}

void Vend::checkRecall() 
{
    // Implementation of checkRecall function
    // ...
}