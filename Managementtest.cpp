#include "Snack.hpp"
#include "Management.hpp"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> recall_items;

void readFile(std::string title){
    string myText;
    //Read from the text file
    fstream MyReadFile(title);
    if (MyReadFile.is_open()){
        while (getline (MyReadFile, myText)) {
            recall_items.pushback(myText);
            }
        //Close the file
        MyReadFile.close();
        }
        else{
            cout << "Error opening file";
            }
    }

int main() {
    readFile("recall.txt");
    Snack tester("UPC code - 132156", "Dorritos", "nacho", "position - A1", 10/*quantity*/, 5.99/*price*/);
    Management test;
    if (test.Recall(tester)){
        std::cout << "Recall - expected result" << std::endl;
    }
    else {
        std::cout << "No recall - error" << std::endl;
    }
    Snack Safe ("UPC code - 132156", "Cheetos", "cheesy", "position - A1", 10/*quantity*/, 5.99/*price*/);
    if (test.Recall(Safe)){
        std::cout << "Recall - error" << std::endl;        
    }
    else {
        std::cout << "No recall - expected result" << std::endl;
    }
        std::cout << "Management Name: " << test.ManagementName() << std::endl;
    return 1;
}
