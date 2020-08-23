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

class CLI
{
public:
	CLI(std::istream in, std::ostream out); //constructor must initialize in and out data members

	void start()
    {
        std::string x;
        int i=0;

        while (_in >> x)
        {
            i++;
        }
         
    }

private:
	std::istream _in;
	std::ostream _out;
	std::unordered_map<std::string, Command> stringToCommandMap;
};




#endif //MAZEPROJECT_CLI_H
