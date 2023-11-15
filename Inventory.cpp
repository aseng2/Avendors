#include <vector>
//#include <compare>  
#include <iostream>
#include "Snack.hpp"
#include "Inventory.hpp"

void Inventory::AddSnackInventory(Snack& SnackObj) {
    SnackList.push_back(SnackObj);
}

void Inventory::BuyInventory(Snack& SnackObj) {
    int Spot = index(SnackObj, SnackList);
    int newvalue = SnackList[Spot].quantity()-1;
	SnackList[Spot].quantity(newvalue);
    AddSalesList(SnackObj);
}

void Inventory::RestockInventory(Snack& SnackObj) {
    int Spot = index(SnackObj, SnackList);
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

int Inventory::index(Snack& SnackObj, std::vector<Snack> List){
    for(int i = 0; i < List.size(); i++){
        if (SnackObj.upcCode() == List[i].upcCode()){
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
    Snack Check = searchList(SnackObj.upcCode());
    if (Check.upcCode() == ""){
        Snack NewSnack (SnackObj.productName(), SnackObj.brandName(), SnackObj.upcCode(), SnackObj.vendingNum(), 1, SnackObj.price(), SnackObj.expireddate() );
        SalesList.push_back(NewSnack);
    }
    else {
        addSale(Check);
    }
}

void Inventory::addSale(Snack& SnackObj){
    int Spot = index(SnackObj, SalesList);
    int newvalue = SalesList[Spot].quantity()+1;
    SalesList[Spot].quantity(newvalue);
}


Snack Inventory::searchList(std::string targetUPCcode) { //problem with searchList, right now hardcoded to only work with salesList
    for (int i = 0; i < SalesList.size(); i++){
        Snack test = SalesList[i];
        if (targetUPCcode == test.upcCode()){
            return test;
        }
    }
    Snack fail;
    return fail;
}

void Inventory::displaySalesHistory(){
    std::cout << "Sales History:" << std::endl;
    std::cout << "Product Name, Brand Name, UPCcode, Amount sold, location, price, expiration date" << std::endl;
    for (int i = 0; i < SalesList.size(); i++){
        Snack Output = SalesList[i];
        std::cout << Output.productName() << ", " << Output.brandName() << ", " << Output.upcCode() << ", "<< Output.quantity() << ", " << Output.vendingNum() << ", " << Output.price() << ", " << Output.expireddate() << std::endl;

    }
}

void Inventory::DisplayRemovedList(){
    std::cout <<"Please Remove These items in the following locations as they may be expired or recalled: " << std::endl;
    for (int i = 0; i < RemoveList.size(); i++) {
        std::cout << RemoveList[i].productName() << " at location: " << RemoveList[i].vendingNum() << std::endl;
    }
}

void Inventory::CreateRemevedList(int CurrentDate) {
    for (int i = 0; i < SnackList.size(); i++){
        if (SnackList[i].expireddate() <= CurrentDate){
            Snack existCheck = searchRemovedList(SnackList[i].upcCode());
            if (existCheck.upcCode() == "") {
                RemoveList.push_back(SnackList[i]);
            }
            //UpdateDate(SnackList[i], 99999999, SnackList); does same as next line but uses the function
            SnackList[i].expireddate(99999999);
            SnackList[i].quantity(0);
        }
        else {
            //recall check with management class implement later when figure out management
            SnackList[i].expireddate(99999999);
            SnackList[i].quantity(0);
        }    
    }
    DisplayRemovedList();
}

void Inventory::UpdateDate(Snack& SnackObj, int NewDate, std::vector<Snack> Modified) {
    int Spot = index(SnackObj, Modified);
    Modified[Spot].expireddate(NewDate);
}

Snack Inventory::searchRemovedList(std::string targetUPCcode) { //problem with searchList, right now hardcoded to only work with salesList
    for (int i = 0; i < RemoveList.size(); i++){
        Snack test = RemoveList[i];
        if (targetUPCcode == test.upcCode()){
            return test;
        }
    }
    Snack fail;
    return fail;
}

std::vector<Snack> Inventory::getSnackList() {
    return SnackList;
  }

void Inventory::setSnackList(std::vector<Snack> newList) {
        SnackList = newList;
    }

std::vector<Snack> Inventory::getSalesList() {
    return SalesList;
}

void Inventory::setSalesList(std::vector<Snack> newList) {
    SalesList = newList;
}

std::vector<Snack> Inventory::getRemoveList() {
    return RemoveList;
}

void Inventory::setRemoveList(std::vector<Snack> newList) {
    RemoveList = newList;
}