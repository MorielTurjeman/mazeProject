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
	}

private:
	FILE *_file;
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
		//add error msg
	}

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end) //we only have one param, no need for loop.
		{
			_name = *start;
			_size = stoi(*(start + 1));
			_mazeGenerationAlgorithm = (*(start + 2));
		}
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
		Maze2d m = model.getMaze(_name); //should return ptr and check if not null (maze not found)
		m.printMaze();					 //should be out << m; but we need to implement the operator
	}
	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{
		if (start != end) //we only have one param, no need for loop.
			_name = *start;
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
	}

private:
	std::string _name;
	std::string _fileName;
};

/************************************************************************************/
//here //
class LoadMazeCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
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
	}

private:
	std::string _name;
	std::string _algorithm;
};

/************************************************************************************/

class DisplaySolutionCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		// for (auto i : Model::solutionCacheMap)
		// {
		// 	if (i)
		// 	{
		// 	}
		// }
	}

private:
	std::string _name;
};

/************************************************************************************/

class ExitCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream &out) override
	{
		exit(0); //todo: check if this function cleans up after the program
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
