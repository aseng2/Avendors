#include "Management.hpp"

std::string const ManagementName() {
    return "Avendors";
};

bool Managment::Recall(Snack object)
{
    if (object.productName() == "Dorritos" ){
        return false;
    }
    return true;
}
