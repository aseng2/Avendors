#include <iostream>
#include <string>
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

	Vend::checkRecall();
}

void Vend::VendItem() 
{
	Sales = Sales + Item.price(); //REPLACE WITH PRICE VARIABLE FROM INVENTORY
	cout << Sales << endl; //DELETE ONCE TEST IS COMPLETE
	salesTracker = salesTracker + 1;
	
}

//void Vend::Notification()
//{
    // Implementation of Notification function
    // ...
//} ADD LATER

void Vend::checkInventory(Inventory List) 
{
	Item = List.search(RequestNum);
    // Implementation of checkInventory function
    // ...
}

void Vend::checkRecall() 
{
	Management Boss;			//this will need to be changed later, but works for now	
		if (Boss.Recall(Item)==false)
		{
			cout << "This object has been recalled" << std::endl;
		}
		else {
			Vend::VendItem();
		}//vend function
}
