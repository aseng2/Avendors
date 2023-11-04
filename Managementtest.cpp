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
            recall_items.push_back(myText);
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
    Snack tester("132156", "Dorritos", "nacho", "position - A1", 10/*quantity*/, 5.99/*price*/);
    Management test("Avendor", recall_items);
    std::string result = (test.Recall(tester))? "Recall - expected result" : "No recall - error";
    std::cout << result << std::endl;
    
    Snack Safe ("132156", "Cheetos", "cheesy", "position - A1", 10/*quantity*/, 5.99/*price*/);
    result = (test.Recall(Safe))? "Recall - error" : "No recall - expected result";
    std::cout << result << std::endl;
    
    std::cout << "Management Name: " << test.getName() << std::endl;
    std::cout << "Items UPC's in recall: << test.display();
    return 1;
}
