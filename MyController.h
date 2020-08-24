//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYCONTROLLER_H
#define MAZEPROJECT_MYCONTROLLER_H
#include "Controller.h"


class MyController : public Controller
{
	shared_ptr<Command> get(const std::string &command)
	{
		auto it = Controller::commandMap.find(command);
		if (it == Controller::commandMap.end())
		{
			return nullptr;
		}
		return it->second;
	}
};


#endif //MAZEPROJECT_MYCONTROLLER_H
