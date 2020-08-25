
#pragma once
#include "Controller.h"
#include "memory"


class MyController : public Controller,public  std::enable_shared_from_this<MyController>
{
public:
	MyController(std::shared_ptr<Model>model, std::shared_ptr<View> view) : model(model), view(view) {
		this->commandMap["generate maze"] = std::make_shared<GenerateMazeCommand>(model, view);
		this->commandMap["dir"]= std::make_shared<DirCommand>(model, view);
		this->commandMap["display"]=std::make_shared<DisplayCommand>(model, view);
		this->commandMap["save maze"]=std::make_shared<SaveMazeCommand>(model, view);
		this->commandMap["load maze"]=std::make_shared<LoadMazeCommand>(model, view);
		this->commandMap["maze size"]=std::make_shared<MazeSizeCommand>(model, view);
		this->commandMap["file size"]=std::make_shared<FileSizeCommand>(model, view);
		this->commandMap["solve"]=std::make_shared<SolveCommand>(model, view);
		this->commandMap["display solution"]=std::make_shared<DisplaySolutionCommand>(model, view);
		this->commandMap["exit"]=std::make_shared<ExitCommand> (model, view);
	}
	shared_ptr<Command> get(const std::string &command)
	{
		return commandMap[command];
	}

	virtual void start() {
		view->start(shared_from_this());
	}

private:
	std::shared_ptr<Model> model;
	std::shared_ptr<View> view;
	std::unordered_map<std::string, shared_ptr<Command>> commandMap;
};


