#include "Management.hpp"

std::string const Management::ManagementName() {
    return "Avendors";
};

bool Management::Recall(Snack object)
{
    if (object.brandName() == "Dorritos" ){
        return false;
    }
    return true;
}
