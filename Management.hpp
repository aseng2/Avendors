#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Snack.hpp"    

class Management {
    public:
    Management();
    ~Management();
    bool Recall(Snack object);
    void setName(std::string newName);
    void setRecall(std::vector<Snack> newRecall);
    void AddSnackRecall(Snack& SnackObj);
    std::string getName();
    void display();
    
    private:
    std::vector<Snack> _recall;
    std::string _name;
    //std::string _location;
    // void operation2(params);             not sure what these for
    //void Operation();                     
};
