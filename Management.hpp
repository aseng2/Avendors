#include <iostream>
#include <string>
#pragma once
#include "Snack.hpp"    //for now as that is the only one i saw on github

class Management {
    public:
    std::string const ManagementName();
    bool Recall(Snack object);
    
    private:
    //void ReportData(inventory);
    // void operation2(params);             not sure what these for
    //void Operation();                     
};