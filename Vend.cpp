#include <iostream>
#include <string>
#include "Vend.hpp"


using namespace std;

Vend::Vend() 
{
    // Constructor implementation
    // Initialize member variables if needed
}

void Vend::Customer_Request(Inventory List) 
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
	Vend::checkInventory(List);
	Vend::checkRecall();
}

void Vend::VendItem() 
{
	Sales = Sales + Item.price(); //REPLACE WITH PRICE VARIABLE FROM INVENTORY
	cout << "$" << Sales << endl; //DELETE ONCE TEST IS COMPLETE
	
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
	Management Boss();			//this will need to be changed later, but works for now	
		if (Boss().Recall(Item)==false) //this shouldn't work but okay
		{
			cout << "This object has been recalled" << std::endl;
		}
		else {
			Vend::VendItem();
		}//vend function
}

void Vend::restockProcess(){
	string upcCode;
	while(upcCode != "0"){
		cout << "you entered the Restock code" << std::endl;
		cout << "Please enter UPC code" << std::endl;
		cout << "or enter '0' to exit" << std::endl;
		cin >> upcCode;
		if (upcCode == "0"){
			break;
		}

	}
}

void Vend::Interface()
{
    cout << "Please Input Money:" << endl;
    cin >> CustomerInput;
	cout << endl;
    std::istringstream iss(CustomerInput);
    double convertedValue;

    if (iss >> convertedValue) {
        // Conversion successful
        CustomerMoney = convertedValue;
        //std::cout << "Conversion successful. Double value: " << convertedValue << std::endl;
    }
    else if (CustomerInput == "AA11") {
        // Check if CustomerInput is equal to "AA11"
        std::cout << "Restocker Code Acknowledged" << std::endl;
    }
    else {
        // Conversion failed and not equal to "AA11"
        std::cout << "Invalid Input" << std::endl;
    }

}