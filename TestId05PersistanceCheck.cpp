#include "Vend.hpp"

int main (){
    Vend SnackBot (20231115);
    Snack Airhead ("Airheads: Soft filled bites", "Airheads", "123456789123", "A2", 5, 5.00, 20251118);
    Snack Lays ("Lays: Barbecue Flavored", "Lays", "321654987321", "A5", 7, 5.00);
    Snack Trash ("trash", "trash", "999999999999", "A1", 3, 9.00, 20231114);
    SnackBot.getSnackList();
    SnackBot.AddSnackInventory(Airhead);
    SnackBot.AddSnackInventory(Lays);
    SnackBot.AddSnackInventory(Trash);
    SnackBot.Menu();
    SnackBot.display();
    SnackBot.displaySalesHistory();
    return 0;
}