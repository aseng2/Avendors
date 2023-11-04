#include "Management.hpp"

Management::Management(std::string name, std::vector<std::string> recall){
    _name = name;
    _recall.clear();
    for(std::string i : recall)
        _recall.push_back(i);
}
Management::Management(){
    _name = "";
    _recall.clear();
}
void Management::setName(std::string newName){
    _name = newName;
    }
std::string Management::getName(){
    return _name;
}
void Management::setRecall(std::vector<std::string> newList){
    _recall.clear();
    for(std::string i : newList)
        _recall.push_back(i);
    }
bool Management::Recall(Snack object)
{
    //check if item is in recall
    for(std::string i : _recall){
        if (i == object.UPC){
            return true;
        }
    }
    return false;
}
