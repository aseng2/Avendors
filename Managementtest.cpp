#include "Snack.hpp"
#include "Management.hpp"

int main() {
    Snack fuck_my_life ("UPC code - 132156", "Brand", "Dorritos", "position - A1", 10/*quantity*/, 5.99/*price*/);
    Managment test;
    if (test.Recall(fuck_my_life)){
        std::cout << "worked";
    }
    else {
        std::cout << "nope";
    }
    return 1;
}