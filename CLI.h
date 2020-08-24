//
// Created by Sapir Ezra on 21/08/2020.
//

#ifndef MAZEPROJECT_CLI_H
#define MAZEPROJECT_CLI_H
#include<iostream>
#include<string>
#include <unordered_map>
#include "Maze2d.h"
#include "Command.h"
#include <memory>
#include "Controller.h"

class CLI
{
public:
	CLI(std::istream& in, std::ostream &out, Controller& c): _in(in), _out(out), c(c)  {} //constructor must initialize in and out data members

	void start()
    {
        std::string x;
        int i=0;

        while (_in >> x)
        {
            i++;
            auto command = c.get(x);
            if (command != nullptr)
            {
               command->setArgs(_in);
               command->execute(); 
            }
        }
    }

private:
	std::istream& _in;
	std::ostream& _out;
    Controller& c;
//	std::unordered_map<std::string, std::shared_ptr<Command>> stringToCommandMap;
};

#endif //MAZEPROJECT_CLI_H
