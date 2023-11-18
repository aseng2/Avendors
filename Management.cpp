#include "Management.hpp"

Management::Management(std::string name, std::vector<Snack> recall){
    _name = name;
    _recall.clear();
    for(Snack i : recall)
        _recall.push_back(i);
}
/*
Management::Management(){
    _name = "";
    _recall.clear();
}       I Think this isn't necessary*/
void Management::setName(std::string newName){
    _name = newName;
    }
std::string Management::getName(){
    return _name;
}
void Management::setRecall(std::vector<Snack> newList){
    _recall.clear();
    for(Snack::Snack i : newList)
        _recall.push_back(i);
    }
bool Management::Recall(Snack object)
{
    //check if item is in recall
    for(Snack i : _recall){
        if (i == object){
            return true;
        }
    }
    return false;
}
void Management::display()
{
    for(Snack i : _recall){
        //find the display function in the snack object
    }
}
        
