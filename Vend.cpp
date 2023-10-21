#pragma once
#include <iostream>
#include <string>
#include "Management.hpp"
#include "Management.cpp"
#include "Vend.hpp"
#include "Inventory.cpp"
#include "Intventory.hpp"


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
		else {
			Vend::VendItem();
		}//vend function

	if (RequestNum == (ValidInput))
	{
		cout << "Vending snack!" << endl;
		VendItem(RequestNum);
	}
	else
	{
		cout << "This item is either out of stock, expired, or has been recalled" << endl;
	}*/

	Vend::checkRecall(RequestNum)
}

void Vend::VendItem() 
{
	Sales = Sales + Snack.price(); //REPLACE WITH PRICE VARIABLE FROM INVENTORY
	cout << Sales << endl; //DELETE ONCE TEST IS COMPLETE
	salesTracker = salesTracker + 1;
	
}

//void Vend::Notification()
//{
    // Implementation of Notification function
    // ...
//} ADD LATER

void Vend::checkInventory() 
{
	Inventory::search(RequestNum);
    // Implementation of checkInventory function
    // ...
}

void Vend::checkRecall() 
{
	Recall(snack object)
		if (false)
		{
			cout << "This object has been recalled"
		}
		else {
			Vend::VendItem();
		}//vend function
}

void main()
{
	Snack Cheetos;
	Cheetos.vendingNum("a1");
	Cheetos.price(4.69);
	Cheetos.quantity(1);
	Inventory Test;

	Test.AddSnackInventory(Cheetos);

	Vend::Customer_Request();
}