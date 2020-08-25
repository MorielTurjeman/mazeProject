//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Model.h"
#include "Maze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "Maze2d.h"
#include "View.h"
#include <filesystem>
namespace fs = std::filesystem;
#include "Searcher.h"
#include "Maze2dSearchable.h"

//here we are using the Command design pattern
//the goal is to separate the Invoker of a Command from the Receiver of that Command

class Command
{
protected:
	Model &model;
	View &view;

public:
	explicit Command(Model &myModel, View &view) : model(myModel), view(view) {}
	virtual void execute(std::ostream &out) = 0;																//pass stdout to update the view
	virtual void setArgs(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end) = 0; //pass stdin to read input
};

/************************************************************************************/

class DirCommand : public Command //todo: change to File class!!!!!!!
{
public:
	// using Command::Command; // allows us to use the parent c`tor
	void execute(std::ostream &out) override
	{
		std::string path = "/path/to/directory";
		for (const auto &entry : fs::directory_iterator(path))
			view.showMsg(entry.path().filename().string());
	}

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end)
		{
			_name = *start;

		}
		else
			view.showMsg("Invalid Parameters");
	}

private:
	
	std::string _name;
};

/************************************************************************************/

class GenerateMazeCommand : public Command
{
public:
	using Command::Command;

	void execute(std::ostream &out) override
	{
		std::shared_ptr<Maze2dGenerator> generator;
		if (_mazeGenerationAlgorithm == "DFS")				   //
			generator = std::make_shared<MyMaze2dGenerator>(); //MyMaze2dGenerator maze;
		else if (this->_mazeGenerationAlgorithm == "SimpleMaze")
			generator = std::make_shared<SimpleMaze2dGenerator>();

		auto m = generator->generate(_size);
		m.setMazeName(_name);
		model.saveMazeToCache(m);

		view.showMsg("Maze " + _name + "is ready");
		//todo: add error msg
	}

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end)
		{
			_name = *start;
			_size = stoi(*(start + 1));
			_mazeGenerationAlgorithm = (*(start + 2));
		}
		else
			view.showMsg("Invalid Parameters");
	}

private:
	std::string _name;
	int _size;
	std::string _mazeGenerationAlgorithm;
};

/************************************************************************************/

//display maze
class DisplayCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		auto m = model.getMaze(_name);
		if (m == nullptr)
		{
			view.showMsg("Maze named " + _name + " not found");
		}
		view.display(*m);
	}
	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end) //we only have one param, no need for loop.
			_name = *start;

		else
			view.showMsg("Invalid Parameters");
	}

private:
	std::string _name;
};

/************************************************************************************/

class SaveMazeCommand : public Command
{
public:
	// using Command::Command;
	void execute(std::ostream &out) override
	{
		auto m = model.getMaze(_name);
		if (m == nullptr)
		{
			view.showMsg("Maze named " + _name + " not found");
		}

		MazeCompression mc;
		std::ofstream file(_fileName);
		if (mc.writeToFile(file, *m) == true)
		{
			view.showMsg("Maze compressed into: " + _fileName + " Successfully");
		}

		else
		{
			view.showMsg("Could not save maze");
		}
	}

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end)
		{
			_name = *start;
			_fileName = (*(start + 1));
		}
		else
			view.showMsg("Invalid Parameters");
	}

private:
	std::string _name;
	std::string _fileName;
};

/************************************************************************************/
class LoadMazeCommand : public Command
{
public:
	// using Command::Command;
	void execute(std::ostream &out) override
	{
		auto m = model.getMaze(_name);
		if (m == nullptr)
		{
			view.showMsg("Maze named " + _name + " not found");
		}

		MazeCompression mc;
		std::ifstream file(_fileName);
		if (mc.readFromFile(file) ! = nullptr)
		{	
			model.saveMazeToCache(m);
			view.showMsg("Maze read from: " + _fileName + " Successfully");

		}

		else
		{
			view.showMsg("Could not load maze");
		}
	}

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{

		if (start != end)
		{
			_name = *start;
			_fileName = (*(start + 1));
		}
		else
			view.showMsg("Invalid Parameters");
	}

private:
	std::string _name;
	std::string _fileName;
};

/************************************************************************************/

class MazeSizeCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
	}

private:
	std::string _name;
};

/************************************************************************************/

class FileSizeCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
	}

private:
	std::string _name;
};

/************************************************************************************/

class SolveCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		Command::model.checkIfMazeIsInCacheMap(_name);

		Maze2dSearchable s(_myMaze);
		if(this->_mazeSolutionAlgorithm == "BFS" || _mazeSolutionAlgorithm == "bfs")
		{
			sol = std::make_shared<BFS<Position>>();
		}
		else if(this->_mazeSolutionAlgorithm == "AStar" || this->_mazeSolutionAlgorithm == "A*")
		{
			sol = std::make_shared<AStar<Position>>()
		}
		/*************/
		std::shared_ptr<Maze2dGenerator> generator;
		if (_mazeSolutionAlgorithm == "DFS")				   //
			generator = std::make_shared<MyMaze2dGenerator>(); //MyMaze2dGenerator maze;
		else if (this->_mazeGenerationAlgorithm == "SimpleMaze")
			generator = std::make_shared<SimpleMaze2dGenerator>();

		auto m = generator->generate(_size);
		m.setMazeName(_name);
		model.saveMazeToCache(m);

		view.showMsg("Maze " + _name + "is ready");
	}
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end)
		{
			_name = *start;
			_mazeSolutionAlgorithm = *(start + 1);
		}
	}

private:
	std::string _name;
	std::string _mazeSolutionAlgorithm;
};

/************************************************************************************/

class DisplaySolutionCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		Command::model.checkIfSolutionIsInCacheMap(_name);
	}
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end) //we only have one param, no need for loop.
		{
			_name = *start;
		}
	}

private:
	std::string _name;
};

/************************************************************************************/

class ExitCommand : public Command // todo: decide if we need it
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		exit(0);
	}
};

/************************************************************************************/

// class Invoker //no need get command because we use advenced method
// {
// public:
// using Command::Command;
// 	void setCommand(Command *command)
// 	{
// 		_command = command;
// 	}

// private:
// 	Command *_command;
// };

/************************************************************************************/
