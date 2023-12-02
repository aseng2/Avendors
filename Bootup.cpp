#include "Vend.hpp"

int main (){
    Vend SnackBot (20231130);
    Snack expired ("Milk", "Cow Milk", "999999999999", "A1", 3, 9.00, 20231114);// this item is expired
    Snack Airhead ("Airheads: Soft filled bites", "Airheads", "456789123456", "A2", 5, 5.00, 20251118);
    Snack Lays ("Lays: Barbecue Flavored", "Lays", "321654987321", "A3", 7, 5.00);
    Snack Cheetos ("Flaming Hot Cheetos", "Cheetos", "012345678987", "B1", 9, 7.00);
    Snack recalled ("Dinamita", "Doritos", "333333333333", "B2", 01, 2.00, 20231231);// this item is on recall
    SnackBot.getSnackList();
    SnackBot.AddSnackInventory(expired);
    SnackBot.AddSnackInventory(Airhead);
    SnackBot.AddSnackInventory(Lays);
    SnackBot.AddSnackInventory(Cheetos);
    SnackBot.AddSnackInventory(recalled);
    SnackBot.Menu();
    cout << "Current Inventory:" << endl;
    SnackBot.display();
    cout << endl;
    SnackBot.displaySalesHistory();
    return 0;
}