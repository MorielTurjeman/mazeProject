//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_COMMAND_H
#define MAZEPROJECT_COMMAND_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Model.h"


//here we are using the Command design pattern
//the goal is to separate the Invoker of a Command from the Receiver of that Command


class Command 
{
protected:
	Model& model;
public:		
	explicit Command(Model& myModel) : model(myModel) {}
	virtual void execute(std::ostream& out)=0; //pass stdout to update the view
	virtual void setArgs(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end) = 0; //pass stdin to read input
};

/************************************************************************************/

class DirCommand : public Command //todo: change to File class!!!!!!!
{
public:
	// DirCommand(FILE * pFile): _file(pFile){}
	void execute(std::ostream& out) override
	{

	}

private:
	FILE* _file;
};

/************************************************************************************/

class GenerateMazeCommand : public Command
{
public:
	// GenerateMazeCommand(std::istream& in): _name(name), _size(size), _mazeGenerationAlgorithm(mazeGenerationAlgorithm){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
	int _size;
	std::string _mazeGenerationAlgorithm;
};

/************************************************************************************/

//display maze
class DisplayCommand : public Command
{
public:
	using Command::Command;
	void execute(std::ostream& out) override
	{
		Maze2d m = model.getMaze(_name); //should return ptr and check if not null (maze not found)
		m.printMaze(); //should be out << m; but we need to implement the operator
	}
	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator  end) override {
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
	// SaveMazeCommand(std::string name, std::string fileName): _name(name), _fileName(fileName){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
	std::string  _fileName;
};

/************************************************************************************/

class LoadMazeCommand : public Command
{
public:
	// LoadMazeCommand(std::string name, std::string fileName): _name(name), _fileName(fileName){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
	std::string  _fileName;
};

/************************************************************************************/

class MazeSizeCommand : public Command
{
public:
	// MazeSizeCommand(std::string name): _name(name){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
};

/************************************************************************************/

class FileSizeCommand : public Command
{
public:
	// FileSizeCommand(std::string name): _name(name){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
};

/************************************************************************************/

class SolveCommand : public Command
{
public:
	// SolveCommand(std::string name, std::string algorithm): _name(name), _algorithm(algorithm){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
	std::string  _algorithm;
};

/************************************************************************************/

class DisplaySolutionCommand : public Command
{
public:
	// DisplaySolutionCommand(std::string name): _name(name){}
	void execute(std::ostream& out) override
	{

	}

private:
	std::string  _name;
};

/************************************************************************************/

class ExitCommand : public Command
{
public:
	// ExitCommand(); //todo: check if necessary!!!!!!!!!!!!!!!!!!
	void execute(std::ostream& out) override
	{

	}
};

/************************************************************************************/

class Invoker //todo: rename later!!!!!!!!!!!!!!!!!!!!!!!!!!! and move
{
public:
	void setCommand(Command *command)
	{
		_command = command;
	}

private:
	Command *_command;
};

/************************************************************************************/


#endif //MAZEPROJECT_COMMAND_H
