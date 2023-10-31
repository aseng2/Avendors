#include "Snack.hpp"
#include "inventory.hpp"
int main() {
    Snack Airhead ("123456", "Airheads", "Airheads: Soft filled bites", "A2", 5, 5.00, 20241030);
    Inventory test;
    test.AddSnackInventory(Airhead);
    Snack Lays ("654321", "Lays", "Lays: Barbecue Flavored", "A5", 7, 5.00);
    test.AddSnackInventory(Lays);
    test.BuyInventory(Airhead);
    test.RestockInventory(Lays);
    test.display();
    return 1;
}