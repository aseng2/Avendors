#include "Vend.hpp"


using namespace std;

Vend::Vend(int CurrentDate) 
{
	setCurrentDate(CurrentDate);//pretty sure this is unecessary but i find it funny
    // Constructor implementation
    // Initialize member variables if needed
}
/*
void Vend::Customer_Request(Inventory List) 
{
	cout << "Welcome! Please Enter Your Snack Request: ";
	cin >> RequestNum;

	//for management false means it is recalled
	Recall(snack object)
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
	}
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
 not working, not using, don't think we need but not deleting yet
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
*/
void Vend::setCurrentDate(int NewDate){
	CurrentDate = NewDate;
}
int Vend::getCurrentDate(){
	return CurrentDate;
}
/*
void Vend::restockProcess(){
	string upcCode;
	Management Avendors;
	Avendors.display();
	CreateRemevedList( CurrentDate );
	while(upcCode != "0"){
		cout << "Please enter UPC code" << std::endl;
		cout << "or enter '0' to exit" << std::endl;
		cin >> upcCode;
		if (upcCode == "0"){
			return;
		}
		string input;
		int number;
		Snack targetToAdd = searchSnackList(upcCode);
		if (targetToAdd.upcCode() == "") {

			cout << "Does not belong in this machine. 0 to overide, anything else to cancel"<< endl;
			
			cin >> input;
			if (input == "0"){
				cout << "Please enter UPCcode: " << endl;
				cin >> input;
				targetToAdd.upcCode(input);
				cout << "Please enter Product Name: " << endl;
				cin >> input;
				targetToAdd.productName(input);
				cout << "Please enter Brand Name: " << endl;
				cin >> input;
				targetToAdd.brandName(input);
				cout << "Please enter Spot in Machine: " << endl;
				cin >> input;
				targetToAdd.vendingNum(input);
				cout << "Please enter quantity to add, must be an integer: " << endl;
				cin >> input;
				number = stoi(input);
				targetToAdd.quantity(number);
				cout << "Please enter date of expiration, as integer year month day: " << endl;
				cin >> input;
				number = stoi(input);
				targetToAdd.expireddate(number);
				cout << "Please enter the price as double: " << endl;
				cin >> input;
				double numberTwo;
				numberTwo = stod(input);
				targetToAdd.price(numberTwo);
				AddSnackInventory(targetToAdd);
			}
		}
		else {
			cout << "Please enter amount adding as an integer: " << endl;
			cin >> number;
			for (int i = 0; i < number; i++){
				restock(targetToAdd);				
				//RestockInventory(targetToAdd);		 trying something
			}
			cout << endl << "Please enter the soonest expiration date as an integer in year month date: " << endl;
			cin >> number;
			cout << endl;
			if (number < targetToAdd.expireddate()){
				UpdateDate(targetToAdd, number, getSnackList());
			}
		}
	}
}*/

void Vend::Menu()
{
    while (CustomerInput != ExitCode)
    {
		cout << endl;
		cout << endl;
		cout << "Current Inventory: " << endl;
		display();
		cout << endl;
        cout << "Please Input Value:" << endl;
        cin >> CustomerInput;
        std::istringstream iss(CustomerInput);
        double convertedValue;

        if (CustomerInput == "0") {
            cout << "Returming Money: $" << CustomerMoney << endl;
            CustomerMoney = 0;
        }
        else if (iss >> convertedValue) {
            // Conversion successful
            CustomerMoney = CustomerMoney + convertedValue;
            convertedValue = 0;
			cout << "Money in machine: $" << CustomerMoney << endl;


            //std::cout << "Conversion successful. Double value: " << convertedValue << std::endl;
        }
        else if (CustomerInput == RestockCode) {
            // Check if CustomerInput is equal to "AA11"
            std::cout << "Restocker Code Acknowledged" << std::endl;
            restockProcess(CurrentDate);
        }
		else if (CustomerInput == ExitCode){
			cout << "shutting down begun" << endl;
			return;
		}
		else if (CustomerInput == SaleHistoryCode){
			cout << "The Sales History is: " << endl;
			displaySalesHistory();
		}
        else {
            // Conversion failed and not equal to "AA11"
			SaleProcess();
        }
    }
}


void Vend::SaleProcess() {
	Management Avendors;
    Snack Customer_Snack = search(CustomerInput);
    if (Customer_Snack.upcCode() == "") {
        cout << "Invalid Input" << endl;
        return;
    }
	else if (Avendors.Recall(Customer_Snack)) {
		cout << "Management has been notified that there is recalled items in the vending machine" << endl;
		cout << "Item on Recall Not for Sale" << endl;
		return;
	}
	else if (Customer_Snack.expireddate() < CurrentDate ){
		cout << "Item is expired. Not for sale" << endl;
		return;
	}
	else if (Customer_Snack.quantity() < 1) {
        cout << "Product is out of stock" << endl;
        return;
    }
	else if (Customer_Snack.price() > CustomerMoney ) {
		cout << "Not enough money, price of object is: $" << Customer_Snack.price() << endl;
		return;
	}

	else {
		if (Customer_Snack.quantity() < 2) {
			cout << "Management has been notified of need of restocking" << endl;
		}
		BuyInventory(Customer_Snack);
		cout << "Vending " << Customer_Snack.productName() << endl;
		if (CustomerMoney > Customer_Snack.price()) {
			cout << "Returning money: $" << CustomerMoney - Customer_Snack.price() << endl;
			CustomerMoney = 0;
			return;
		}
		CustomerMoney = 0;
		return;

	}

}