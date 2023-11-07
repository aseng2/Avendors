#pragma once
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "Snack.hpp"
#include "Management.hpp"

class Inventory {
private:
    std::vector<Snack> SnackList;
    std::vector<Snack> SalesList;
    std::vector<Snack> RemoveList;

public:
    void AddSnackInventory(Snack& SnackObj);
    void BuyInventory(Snack& SnackObj);
    void RestockInventory(Snack& SnackObj);
    Snack search(std::string target);
    void display();
    void AddSalesList(Snack& SnackObj);
    Snack searchSalesList(std::string targetUPCcode);
    int index(Snack& SnackObj, std::vector<Snack> List);
    void addSale(Snack& SnackObj);
    void displaySalesHistory();
    void CreateRemevedList(int CurrentDate);
    void DisplayRemovedList();
    void emptyRemovedList();
    int RemovedListindex();
    void UpdateDate(Snack& SnackObj, int NewDate, std::vector<Snack> Modified);


};

#endif

