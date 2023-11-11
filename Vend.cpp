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
		cout << "Please enter UPC code" << std::endl;
		cout << "or enter '0' to exit" << std::endl;
		cin >> upcCode;
		if (upcCode == "0"){
			break;
		}
		Snack targetToAdd = searchList(upcCode);

		if (targetToAdd.upcCode() == "") {
			cout << "Does not belong in this machine. 0 to overide, anything else to cancel"<< endl;
			string input;
			cin >> input;
			if (input == "0"){
				cout << "Please enter UPCcode: " << endl;
				
			}
			
		}

	}
}

void Vend::Menu()
{
    while (CustomerInput != ExitCode)
    {
        cout << "Please Input Value:" << endl;
        cin >> CustomerInput;
        cout << endl;
        std::istringstream iss(CustomerInput);
        double convertedValue;

        if (CustomerInput == "0") {
            cout << "Returming Money: $" << CustomerMoney << endl;
            CustomerMoney = 0;
        }
        else if (iss >> convertedValue) {
            // Conversion successful
            CustomerMoney = CustomerMoney + convertedValue;
            convertedValue == 0;



            //std::cout << "Conversion successful. Double value: " << convertedValue << std::endl;
        }
        else if (CustomerInput == "AA11") {
            // Check if CustomerInput is equal to "AA11"
            std::cout << "Restocker Code Acknowledged" << std::endl;
            restockProcess();
        }
        else {
            // Conversion failed and not equal to "AA11"
            std::cout << "Invalid Input" << std::endl;
			SaleProcess();
        }
    }
}


void Vend::SaleProcess() {
    Snack Customer_Snack = search(CustomerInput);
    if (Customer_Snack.upcCode() == "") {
        cout << "Invalid Input";
        return;
    }
	if (Customer_Snack.quantity() < 1) {
        cout << "Product is out of stock";
        return;
    }
    //add expiration date check here

}