#pragma once
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "Snack.hpp"

class Inventory {
private:
    std::vector<Snack> SnackList;
    std::vector<Snack> SalesList;

public:
    void AddSnackInventory(Snack& SnackObj);
    void BuyInventory(Snack& SnackObj);
    void RestockInventory(Snack& SnackObj);
    Snack search(std::string target);
    void display();
    void AddSalesList(Snack& SnackObj);
    Snack searchSalesList(std::string targetUPCcode);
    int index(Snack& SnackObj);
};

#endif

