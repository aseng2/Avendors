#include "Snack.hpp"
#include "Management.hpp"

int main() {
    Snack tester ("UPC code - 132156", "Dorritos", "nacho", "position - A1", 10/*quantity*/, 5.99/*price*/);
    Management test;
    if (test.Recall(tester)){
        std::cout << "No recall - error" << std::endl;
    }
    else {
        std::cout << "Recall - expected result" << std::endl;
    }
    Snack Safe ("UPC code - 132156", "Cheetos", "cheesy", "position - A1", 10/*quantity*/, 5.99/*price*/);
    if (test.Recall(Safe)){
        std::cout << "No recall - expected result" << std::endl;
    }
    else {
        std::cout << "Recall - error" << std::endl;
    }
        std::cout << "Management Name: " << test.ManagementName() << std::endl;
    return 1;
}