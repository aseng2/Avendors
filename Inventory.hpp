#pragma once
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include "snack.hpp"

class Inventory {
private:
    std::vector<Snack> SnackList;

public:
    void AddSnackInventory(Snack& SnackObj);
    void BuyInventory(Snack& SnackObj);
    void RestockInventory(Snack& SnackObj);
    Snack search(std::string target);
    void display();
};

#endif

