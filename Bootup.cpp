#include "Vend.hpp"

int main (){
    Vend SnackBot (20231115);
    Snack expired ("expired item", "expired item", "999999999999", "A1", 3, 9.00, 20231114);// this item is expired
    Snack Airhead ("Airheads: Soft filled bites", "Airheads", "123456789123", "A2", 5, 5.00, 20251118);
    Snack Lays ("Lays: Barbecue Flavored", "Lays", "321654987321", "A3", 7, 5.00);
    Snack recalled ("Flaming Hot Cheetos", "Cheetos", "012345678987", "B1", 9, 7.00);// this item is on recall
    SnackBot.getSnackList();
    SnackBot.AddSnackInventory(expired);
    SnackBot.AddSnackInventory(Airhead);
    SnackBot.AddSnackInventory(Lays);
    SnackBot.AddSnackInventory(recalled);
    SnackBot.Menu();
    SnackBot.display();
    SnackBot.displaySalesHistory();
    return 0;
}