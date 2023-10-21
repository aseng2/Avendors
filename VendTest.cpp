#include "vend.hpp"

int main() {
    Inventory Supplies;
    Vend SnackBot;
    Snack Airhead ("123456", "Airheads", "Airheads: Soft filled bites", "A2", 5, 5.00);
    Supplies.AddSnackInventory(Airhead);
    Snack Lays ("654321", "Lays", "Lays: Barbecue Flavored", "A5", 7, 5.00);
    Supplies.AddSnackInventory(Lays);
    SnackBot.Customer_Request(Supplies);
    

}