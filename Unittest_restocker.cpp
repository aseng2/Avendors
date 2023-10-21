#include "restocker.h"


int main()
{
    Restocker James;
    Snack lays;

    James.set_restocker_name("James");
    
    
    
    cout <<  "Hi " << James.get_restocker_name() << endl;
    cout << "Please check the inventory " << endl;
    //James.display_employee();

    James.RestockInventory(lays);

    cout << lays.quantity() << endl;
    
    return 0;
}