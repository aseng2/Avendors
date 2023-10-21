#include <vector>
//#include <compare>  
#include <iostream>
#include "snack.hpp"


#include "Inventory.hpp"
#include <iostream>

void Inventory::AddSnackInventory(Snack& SnackObj) {
    SnackList.push_back(SnackObj);
}

void Inventory::BuyInventory(Snack& SnackObj) {
    int newvalue = SnackObj.quantity() -1;
	std::cout << newvalue << std::endl;
	SnackObj.quantity(newvalue);
}

void Inventory::RestockInventory(Snack& SnackObj) {
    int current = SnackObj.quantity() + 1;
    SnackObj.quantity(current);
}

Snack Inventory::search(std::string target) {
    int LoopEnd = SnackList.size();
    int start = 0;
    while (start < LoopEnd) {
        Snack test = SnackList[start];
        if (test.vendingNum() == target) {
            return test;
        }
        start++;
    }
}

void Inventory::display() {
    int LoopEnd = SnackList.size();
    int start = 0;
    std::cout << "UPC Code, Brand Name, Product Name, quantitiy, spot, price" << std::endl;
    while (start < LoopEnd) {
        Snack Output = SnackList[start];
        std::cout << Output.productName() << ", " << Output.brandName() << ", " << Output.upcCode() << ", "<< Output.quantity() << ", " << Output.vendingNum() << ", " << Output.price() << std::endl;
        start++;
    }
}


