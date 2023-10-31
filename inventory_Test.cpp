#include "Snack.hpp"
#include "inventory.hpp"
int main() {
    Inventory test;
    Snack DefaultTest;
    test.AddSnackInventory(DefaultTest);
    Snack Airhead ("Airheads: Soft filled bites", "Airheads", "123456789123", "A2", 5, 5.00, 20241030);
    test.AddSnackInventory(Airhead);
    Snack Lays ("Lays: Barbecue Flavored", "Lays", "321654987321", "A5", 7, 5.00);
    test.AddSnackInventory(Lays);
    test.BuyInventory(Airhead);
    test.RestockInventory(Lays);
    test.display();
    Lays.quantity(10);
    std::cout << Lays.quantity();
    return 1;
}