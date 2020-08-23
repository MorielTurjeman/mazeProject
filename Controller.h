//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_CONTROLLER_H
#define MAZEPROJECT_CONTROLLER_H
#include <unordered_map>
#include <string>
#include "Command.h"


class Controller
{
public:
	Controller(){}
	~Controller(){}
	Command* get(const std::string &command)
	{
		auto it = commandMap.find(command);
		if (it == commandMap.end())
		{
			return nullptr;
		}
	}

private:
	std::unordered_map<std::string, Command*> commandMap;
};


#endif //MAZEPROJECT_CONTROLLER_H
