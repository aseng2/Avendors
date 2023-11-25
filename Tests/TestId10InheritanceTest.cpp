#include "restocker.h"
int main(){
    Restocker Joe;
    Joe.set_restocker_name("Joe");
    std::cout << Joe.get_restocker_name() << endl;
    Snack Airhead ("Airheads: Soft filled bites", "Airheads", "123456789123", "A2", 5, 5.00, 20251118);
    Snack Lays ("Lays: Barbecue Flavored", "Lays", "321654987321", "A5", 7, 5.00);
    Joe.AddSnackInventory(Airhead);
    Joe.display();
    Joe.restock(Airhead);
    Joe.display();
}