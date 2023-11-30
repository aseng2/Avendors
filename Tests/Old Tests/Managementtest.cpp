#include "Snack.hpp"
//#include "Snack.cpp"
#include "Management.hpp"
//#include "Management.cpp"
#include <iostream>
#include <vector>

//Fill the recall with these items on the recall list
void fill_recall(Management& passed);
void fill_recall(Management& passed){
    Snack snack1 ("Nacho cheese", "Doritos", "132156", "A1", 10, 5.00, 12102023);
    Snack snack2 ("Nacho Ranch", "Doritos", "1111111111", "A2", 01, 2.00, 12312023);
    Snack snack3 ("Puffs", "Cheetos", "2222222222", "B1", 01, 2.00, 12312023);
    Snack snack4 ("Flaming Hot", "Doritos", "333333333", "B2", 01, 2.00, 1231202);
    passed.AddSnackRecall(snack1);
    passed.AddSnackRecall(snack2);
    passed.AddSnackRecall(snack3);
    passed.AddSnackRecall(snack4);
}

int main() {
    Management test;
    test.setName("Avendors");
    fill_recall(test);

    //Order of parameters when instantiate a Management class
    //string productName, string brandName, string upcCode, string vendingNum, int quantity, double price, int _expireddate
    
    Snack tester("Nacho cheese", "Doritos", "132156", "A1", 10/*quantity*/, 5.00/*price*/, 12102023);
    std::string result = (test.Recall(tester))? "Recall - expected result" : "No recall - error";
    std::cout << result << std::endl;
    
    Snack Safe ("Cheetos", "Cheesy", "132156","A2", 10/*quantity*/, 5.99/*price*/, 12122023);
    result = (test.Recall(Safe))? "Recall - error" : "No recall - expected result";
    std::cout << result << std::endl;
    
    std::cout << "Management Name: " << test.getName() << std::endl;
    std::cout << "Items in recall: " << std::endl;
    std::cout << "UPC Code" << "\tProd Brand" << "\tProd Name" << "\tVend #" << "\tQty" << "\tPrice" << "\tExp Date" << std::endl;
    test.display();
    return 1;
}
