#include "restocker.h"


int main()
{
    Restocker James;

    James.set_id(3223);

    cout << " show record " << James.get_id() << endl;
    //James.display_employee();

    return 0;
}