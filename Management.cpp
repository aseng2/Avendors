#include "Management.hpp"

Management::Management(){
    this->_name = "Avendors";
    //this->_location = "123456 Fake Road Way, Fullerton CA";
    Snack snack1 ("Nacho cheese", "Doritos", "123456789123", "A1", 10, 5.00);
    Snack snack2 ("Nacho Ranch",  "Doritos", "111111111111", "A2", 01, 2.00);
    Snack snack3 ("Famin Puff",   "Cheetos", "222222222222", "B1", 01, 2.00);
    Snack snack4 ("Dinamita",     "Doritos", "333333333333", "B2", 01, 2.00);
    _recall.push_back(snack1);
    _recall.push_back(snack2);
    _recall.push_back(snack3);
    _recall.push_back(snack4);
}
Management::~Management(){};
void Management::setName(std::string newName){
    this->_name = newName;
    }
std::string Management::getName(){
    return _name;
}
void Management::setRecall(std::vector<Snack> newList){
    this->_recall.clear();
    for(int i = 0; i < newList.size() ; i++){
        Snack Temp = newList[i];
        this->_recall.push_back(Temp);
        }    
    }
bool Management::Recall(Snack object)
{
    //check if item is in recall
    for(Snack i : _recall){
        if (i.upcCode() == object.upcCode()){
            return true;
        }
    }
    return false;
}
void Management::AddSnackRecall(Snack& SnackObj)
{
    this->_recall.push_back(SnackObj);
}
void Management::display()
{
    std::cout << "Management Name: " << this->_name << "\n";
    //std::cout << "Address: " << this ->_location << "\n";
    std::cout << "Items in recall: " << std::endl;
    std::cout << "UPC Code" << "\tBrand" << "\tProd Name" << "\tVend #" << "\tQty" << "\tPrice" << "\tExp Date" << std::endl;
    for(Snack temp : _recall){
        std::cout << temp.upcCode() << "\t" << temp.brandName() << "\t" << temp.productName() << "\t" << temp.vendingNum() << "\t"  << temp.quantity() << "\t"  << temp.price() << "\t"  << temp.expireddate() << "\n";
    }
}   
