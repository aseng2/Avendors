#include "restocker.h"
// testing



Restocker::Restocker()
{
	name = " ";
}

//Restocker::Restocker(string name)
//{
	//this->name = name;
//}

Restocker::~Restocker()
{

}


void Restocker::set_restocker_name(string name)
{
	this->name = name;
}


string Restocker::get_restocker_name()
{
	return name;
}


void Restocker::restock(Snack snack)
{
	RestockInventory(snack);
}


void Restocker::restockProcess(int CurrentDate){
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
}

//void Restocker::display_employee()
//{
	//cout << " employee ID:";
	//cout << name << endl;
//}