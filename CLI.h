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
#include <sstream>
#include "Controller.h"

class CLI
{
public:
	CLI(std::istream& in, std::ostream &out, Controller& c): _in(in), _out(out), controller(c)  {} //constructor must initialize in and out data members
    vector<std::string> breakToWords(std::string line)
    {
        std::stringstream ss(line);
        std::vector<std::string> words;
        do {
            std::string word;
            ss >> word;
            words.push_back(word);
        } while (ss);

        return words;
    }
	void start()
    {
        std::string x;
        int i=0;

        while (_in >> x)
        {
            i++;
            std::string line;
            std::getline(_in, line);
            auto words = breakToWords(line);
            int commandLen = 0;
            auto command = controller.get(words[0] + " " + words[1]);
            if (command != nullptr)
            {
                commandLen = 2;
            }
            else
            {
                command = controller.get(words[0]);
                commandLen = 1;
            }
            

            if (command != nullptr)
            {
               command->setArgs(words.begin() + commandLen, words.end());
               command->execute(_out); 
            }
        }
    }

private:
	std::istream& _in;
	std::ostream& _out;
    Controller& controller;
//	std::unordered_map<std::string, std::shared_ptr<Command>> stringToCommandMap;
};

#endif //MAZEPROJECT_CLI_H
