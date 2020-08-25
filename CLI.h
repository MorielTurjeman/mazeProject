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
    // {
    //     std::stringstream ss(line);
    //     std::vector<std::string> words;
    //     do
    //     {
    //         std::string word;
    //         ss >> word;
    //         words.push_back(word);
    //     } while (ss);

    //     return words;
    // }
    void start(std::shared_ptr<Controller> controller);
    // {
    //     std::string x;
    //     int i = 0;

    //     while (_in >> x)
    //     {
    //         // 1. the cli reads a line from the user
    //         // 2. it passes it to the controller
    //         // 3. the controller determines which command to run
    //         // 4. the controller returns the command
    //         // 5. the cli will pass the arguments to the command
    //         // 6. the cli will execute the command

    //         i++;
    //         std::string line;
    //         std::getline(_in, line);
    //         auto words = breakToWords(line);
    //         int commandLen = 0;
    //         auto command = controller.get(words[0] + " " + words[1]);
    //         if (command != nullptr)
    //         {
    //             commandLen = 2;
    //         }
    //         else
    //         {
    //             command = controller.get(words[0]);
    //             commandLen = 1;
    //         }

    //         if (command != nullptr)
    //         {
    //             command->setArgs(words.begin() + commandLen, words.end());
    //             command->execute(_out);
    //         }
    //     }
    // }

    std::istream &getIn();// { return _in; }
    std::ostream &getout();// { return _out; }
    void setController(std::shared_ptr<Controller> controller);
    // {
    //     controller = controller;
    // }
private:
    std::istream &_in;
    std::ostream &_out;
    //	std::unordered_map<std::string, std::shared_ptr<Command>> stringToCommandMap;
};

