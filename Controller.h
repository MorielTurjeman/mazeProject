//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_CONTROLLER_H
#define MAZEPROJECT_CONTROLLER_H
#include <unordered_map>
#include <string>
#include "Command.h"
#include "Maze2d.h"
#include "Model.h"

class Controller
{
public:
	Controller(Model& myModel)
	{
		commandMap["display"] = std::make_shared<DisplayCommand>(myModel);
		// commandMap["maze size"] = std::make_shared<MazeSizeCommand>(name);
		// commandMap["file size"] = std::make_shared<FileSizeCommand>(name);
		// commandMap["display solution"] = std::make_shared<DisplaySolutionCommand>(name);
	}

	~Controller(){}

	virtual shared_ptr<Command> get(const std::string &command) = 0;

protected:
	std::unordered_map<std::string, shared_ptr<Command>> commandMap;
};


#endif //MAZEPROJECT_CONTROLLER_H
