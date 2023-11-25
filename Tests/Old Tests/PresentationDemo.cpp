#include "vend.hpp"
#include  <iostream>
int main() {
    Inventory Supplies;
    Vend SnackBot;
    std::string UPC;
    std::string Brand;
    std::string product;
    std::string position;
    int quantity;
    double price;
    std::cout << "Enter UPC code: ";
    std::cin >> UPC;
    std::cout  << std::endl << "Enter Brand: ";
    std::cin >> Brand;
    std::cout << std::endl << "Enter Product: ";
    std::cin >> product;
    std::cout << std::endl << "Enter Position: ";
    std::cin >> position;
    std::cout << std::endl << "Enter Quantity: ";
    std::cin >> quantity;
    quantity --;
    std::cout << std::endl << "Enter Price: ";
    std::cin >> price;
    std::cout << std::endl;
    Snack Presentation (UPC, Brand, product, position, quantity, price);
    Supplies.AddSnackInventory(Presentation);
    SnackBot.Customer_Request(Supplies);
    std::cout << "items in inventory are " << std::endl;
    Supplies.display();
    return 0;
}
