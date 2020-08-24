//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_CONTROLLER_H
#define MAZEPROJECT_CONTROLLER_H
#include <unordered_map>
#include <string>
#include "Command.h"
#include "Maze2d.h"


class Controller
{
public:
//	Controller(Maze2d& maze)
//	{
//		commandMap["dir"] = new DirCommand();
//	}

	Controller(std::string name)
	{
		commandMap["display"] = new DisplayCommand(name);
		commandMap["maze size"] = new MazeSizeCommand(name);
		commandMap["file size"] = new FileSizeCommand(name);
		commandMap["display solution"] = new DisplaySolutionCommand(name);
	}
	Controller()
	{
		commandMap["exit"] = new ExitCommand();
	}
	Controller(FILE * pFile)
	{
		commandMap["dir"] = new DirCommand(pFile);
	}
	~Controller(){}
	Command* get(const std::string &command)
	{
		auto it = commandMap.find(command);
		if (it == commandMap.end())
		{
			return nullptr;
		}
		return it->second;
	}

private:
	std::unordered_map<std::string, Command*> commandMap;
};


#endif //MAZEPROJECT_CONTROLLER_H