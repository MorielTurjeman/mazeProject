//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYCONTROLLER_H
#define MAZEPROJECT_MYCONTROLLER_H
#include "Controller.h"


class MyController : public Controller
{
public:
	MyController(Model& model, View& view ) : model(model), view(view) {
		this->commandMap["generate maze"] = std::make_shared<GenerateMazeCommand>(model, view);//add generate maze command

	}
	shared_ptr<Command> get(const std::string &command)
	{
		auto it = Controller::commandMap.find(command);
		if (it == Controller::commandMap.end())
		{
			return nullptr;
		}
		return it->second;
	}

private:
	Model& model;
	View& view;
};


#endif //MAZEPROJECT_MYCONTROLLER_H
