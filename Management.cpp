#include "Management.hpp"

Management::Management(){
    this->_name = "";
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
    for(Snack i : _recall){
        //find the display function in the snack object
        std::cout << i << std::endl;
    }
}   
