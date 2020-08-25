//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>
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
#include "MazeCompression.h"

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
	using Command::Command; // allows us to use the parent c`tor
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
		model.saveMazeToCache(std::make_shared<Maze2d>(m));

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
	using Command::Command;
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
	using Command::Command;
	void execute(std::ostream &out) override
	{
		auto m = model.getMaze(_name);
		if (m == nullptr)
		{
			view.showMsg("Maze named " + _name + " not found");
		}

		MazeCompression mc;
		std::ifstream file(_fileName);
		// if (mc.readFromFile(file) ! = nullptr)
		// {	
		// 	model.saveMazeToCache(m);
		// 	view.showMsg("Maze read from: " + _fileName + " Successfully");

		// }

		// else
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
		auto maze = Command::model.getMaze(_name);
		if (maze == NULL)
		{
			view.showMsg("Maze not found. \n");
			return;
		}
		//size of data members:
		auto _sizeOfMazeVector = sizeof(int)*(maze->getMaze().size()* maze->getMaze().size());
		auto _sizeOfStartEndCurrentPosition = sizeof(Position)*3;
		auto _sizeOfMazeName = maze->getMazeName().size();
		auto _sumOfMazeSize = _sizeOfMazeVector + _sizeOfStartEndCurrentPosition + _sizeOfMazeName;
		view.showMsg("Size of " + _name + "in memory is: " + std::to_string(_sumOfMazeSize) + "bytes of memory.");
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

class FileSizeCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		std::ifstream _infile;
		_infile.open(_name, std::ios::in | std::ios::binary);
		_infile.seekg(0, std::ios::end);
		view.showMsg("Size of " + _name + "in file is: " + std::to_string(_infile.tellg()) + "bytes of memory.");
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

class SolveCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		shared_ptr<Maze2d> _maze = Command::model.getMaze(_name);
		if (_maze == NULL)
		{
			view.showMsg("Maze not found. \n");
			return;
		}
		Maze2dSearchable s(*_maze);

		if(this->_mazeSolutionAlgorithm == "BFS" || _mazeSolutionAlgorithm == "bfs")
		{
			BFS<Position> bfs;
			auto solBFS = bfs.search(s);
			view.showMsg("Solution for " + _name + "is ready");
			for (auto p : solBFS.getPath())
			{
				view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
			}
		}
		if(this->_mazeSolutionAlgorithm == "AStar arial" || this->_mazeSolutionAlgorithm == "A* arial")
		{
			AerialDistance ad(s.getGoalState());
			AStar<Position> Arialdis(ad);
			auto solAerial = Arialdis.search(s);
			view.showMsg("Solution for " + _name + "is ready");
			for (auto p : solAerial.getPath())
			{
				view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
			}
		}
		if(this->_mazeSolutionAlgorithm == "AStar Manhattan" || this->_mazeSolutionAlgorithm == "A* Manhattan")
		{
			ManhattanDistance amd(s.getGoalState());
			AStar<Position> manhattendis(amd);
			auto solManhattan = manhattendis.search(s);
			view.showMsg("Solution for " + _name + "is ready");
			for (auto p : solManhattan.getPath())
			{
				view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
			}
		}
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
		auto sol = Command::model.checkIfSolutionIsInCacheMap(_name);
		if (sol == NULL)
		{
			view.showMsg("Solution for " + _name + "not found. \n");
			return;
		}
		for (auto p : sol->getPath())
		{
			view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
		}
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
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{}
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
