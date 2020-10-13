#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "Maze2d.h"
#include "Command.h"
#include <memory>
#include <sstream>

class Controller;

class CLI
{
public:
    CLI(std::istream &in, std::ostream &out) : _in(in), _out(out) {} //constructor must initialize in and out data members
    vector<std::string> breakToWords(std::string line);
   
    void start(std::shared_ptr<Controller> controller);


    std::istream &getIn();// { return _in; }
    std::ostream &getout();// { return _out; }
    void setController(std::shared_ptr<Controller> controller);
    
private:
    std::istream &_in;
    std::ostream &_out;
   
};

