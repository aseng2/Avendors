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
    Snack searchList(std::string targetUPCcode);
    int index(Snack& SnackObj, std::vector<Snack> List);
    void addSale(Snack& SnackObj);
    void displaySalesHistory();
    void CreateRemevedList(int CurrentDate);
    void DisplayRemovedList();
    Snack searchRemovedList(std::string targetUPCcod);
    Snack searchSnackList(std::string targetUPCcode);
    void UpdateDate(Snack& SnackObj, int NewDate, std::vector<Snack> Modified);
    std::vector<Snack> getSnackList();
    void setSnackList(std::vector<Snack> newList);
    std::vector<Snack> getSalesList();
    void setSalesList(std::vector<Snack> newList);
    std::vector<Snack> getRemoveList();
    void setRemoveList(std::vector<Snack> newList);

};

#endif

