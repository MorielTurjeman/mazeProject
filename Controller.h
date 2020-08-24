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
	Controller(std::string name)
	{
		commandMap["display"] = std::make_shared<DisplayCommand>(name);

		commandMap["maze size"] = std::make_shared<MazeSizeCommand>(name);
		commandMap["file size"] = std::make_shared<FileSizeCommand>(name);
		commandMap["display solution"] = std::make_shared<DisplaySolutionCommand>(name);
	}
	Controller()
	{
		commandMap["exit"] = std::make_shared<ExitCommand>();
	}
	Controller(FILE * pFile)
	{
		commandMap["dir"] = std::make_shared<DirCommand>(pFile);
	}
	~Controller(){}
	shared_ptr<Command> get(const std::string &command)
	{
		auto it = commandMap.find(command);
		if (it == commandMap.end())
		{
			return nullptr;
		}
		return it->second;
	}

private:
	std::unordered_map<std::string, shared_ptr<Command>> commandMap;
};


#endif //MAZEPROJECT_CONTROLLER_H
