#include <iostream>
#include <string>
#include <vector>
#pragma once
#include "Snack.hpp"    

class Management {
    public:
    Management(std::string name, std::vector<std::string> recall);
    bool Recall(Snack object);
    void setName(std::string newName);
    void setRecall(std::vector<std::string> newRecall);
    std::string getName();
    void display();
    
    private:
    std::vector<std::string> _recall;
    std::string _name;
    // void operation2(params);             not sure what these for
    //void Operation();                     
};
