#include "Management.hpp"

std::string const Management::ManagementName() {
    return "Avendors";
};

bool Management::Recall(Snack object, vector<std::string> v)
{
    //check the vector v
    for(std::string i : v){
        if (i == object.UPC){
            return true;
        }
    }
    return false;
}
