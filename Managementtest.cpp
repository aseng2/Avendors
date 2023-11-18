#include "Snack.hpp"
#include "Management.hpp"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<Snack> recall_items;

void readFile(std::string title){
    std::string myText;
    //Read from the text file
    std::fstream MyReadFile(title);
    if (MyReadFile.is_open()){
        while (getline (MyReadFile, myText)) {
            //check for read from file for right parameters in order
            Snack temp(myText[0], myText[1], myText[2], myText[3], myText[4], myText[5], myText[6]);
            recall_items.push_back(temp);
            }
        //Close the file
        MyReadFile.close();
        }
        else{
            std::cout << "Error opening file";
            }
    }

int main() {
    readFile("recall.txt");
    Management test("Avendor", recall_items);

    //ORder of parameters when instantiate a Management class
    //string productName, string brandName, string upcCode, string vendingNum, int quantity, double price, int _expireddate
    
    Snack tester("Nacho cheese", "Doritos", "132156", "A1", 10/*quantity*/, 5.00/*price*/, 12102023);
    std::string result = (test.Recall(tester))? "Recall - expected result" : "No recall - error";
    std::cout << result << std::endl;
    
    Snack Safe ("Cheetos", "Cheesy", "132156","A2", 10/*quantity*/, 5.99/*price*/, 12122023);
    result = (test.Recall(Safe))? "Recall - error" : "No recall - expected result";
    std::cout << result << std::endl;
    
    std::cout << "Management Name: " << test.getName() << std::endl;
    // std::cout << "Items in recall: " << test.display(); this line not working, probably becuase there is no display function
    return 1;
}
