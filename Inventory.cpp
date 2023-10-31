#include <vector>
//#include <compare>  
#include <iostream>
#include "Snack.hpp"
#include "Inventory.hpp"

void Inventory::AddSnackInventory(Snack& SnackObj) {
    SnackList.push_back(SnackObj);
}

void Inventory::BuyInventory(Snack& SnackObj) {
    int Spot = index(SnackObj);
    int newvalue = SnackList[Spot].quantity()-1;
	SnackList[Spot].quantity(newvalue);
}

void Inventory::RestockInventory(Snack& SnackObj) {
    int Spot = index(SnackObj);
    int newvalue = SnackList[Spot].quantity()+1;
    SnackList[Spot].quantity(newvalue);
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
    Snack fail;
    return fail;
}

int Inventory::index(Snack& SnackObj){
    for(int i = 0; i < SnackList.size(); i++){
        if (SnackObj.upcCode() == SnackList[i].upcCode()){
            return i;
        }
    }
    return -1;
}

void Inventory::display() {
    int LoopEnd = SnackList.size();
    int start = 0;
    std::cout << "Product Name, Brand Name, UPCcode, quantitiy, location, price, expiration date" << std::endl;
    while (start < LoopEnd) {
        Snack Output = SnackList[start];
        std::cout << Output.productName() << ", " << Output.brandName() << ", " << Output.upcCode() << ", "<< Output.quantity() << ", " << Output.vendingNum() << ", " << Output.price() << ", " << Output.expireddate() << std::endl;
        start++;
    }
}

void Inventory::AddSalesList(Snack& SnackObj) {
    Snack Check = searchSalesList(SnackObj.upcCode());
    if (Check.upcCode() == ""){
        Snack NewSnack (SnackObj.productName(), SnackObj.brandName(), SnackObj.upcCode(), SnackObj.vendingNum(), 1, SnackObj.price(), SnackObj.expireddate() );
        SalesList.push_back(NewSnack);
    }
    else {
        RestockInventory(Check);
    }
}

Snack Inventory::searchSalesList(std::string targetUPCcode) {
    if (SalesList.size() == 0){
        Snack fail;
        return fail;
    }
    for (int i = 0; i < SalesList.size(); i++){
        Snack test = SalesList[i];
        if (targetUPCcode == test.upcCode()){
            return test;
        }
    }
    Snack fail;
    return fail;
}