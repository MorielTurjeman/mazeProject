//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_COMMAND_H
#define MAZEPROJECT_COMMAND_H
#include <string>
#include "Controller.h"


//here we are using the Command design pattern
//the goal is to separate the Invoker of a Command from the Receiver of that Command
class Command
{
public:
	virtual void execute()=0;
};

/************************************************************************************/

class DirCommand : public Command //todo: change to File class!!!!!!!
{
public:
	DirCommand(File* pFile): _file(pFile){}
	void execute() override
	{

	}

private:
	File* _file;
};

/************************************************************************************/

class GenerateMazeCommand : public Command
{
public:
	GenerateMazeCommand(std::string name, int size, std::string mazeGenerationAlgorithm): _name(name), _size(size), _mazeGenerationAlgorithm(mazeGenerationAlgorithm){}
	void execute() override
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
	DisplayCommand(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string _name;
};

/************************************************************************************/

class SaveMazeCommand : public Command
{
public:
	SaveMazeCommand(std::string name, std::string fileName): _name(name), _fileName(fileName){}
	void execute() override
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
	LoadMazeCommand(std::string name, std::string fileName): _name(name), _fileName(fileName){}
	void execute() override
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
	MazeSizeCommand(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string  _name;
};

/************************************************************************************/

class FileSizeCommand : public Command
{
public:
	FileSizeCommand(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string  _name;
};

/************************************************************************************/

class SolveCommand : public Command
{
public:
	SolveCommand(std::string name, std::string algorithm): _name(name), _algorithm(algorithm){}
	void execute() override
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
	DisplaySolutionCommand(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string  _name;
};

/************************************************************************************/

class ExitCommand : public Command
{
public:
	ExitCommand(); //todo: check if necessary!!!!!!!!!!!!!!!!!!
	void execute() override
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

class NameLater //take #include "Controller.h"
{
	void getCommand()
	{
		std::string  command = "";
		while(command.compare("exit") != 0)
		{
			Controller* controller = new Controller();
			std::cout << "Please enter command: " << std::endl;
			std::in >> command;

			Command* cmd = controller->get(command);

			if (nullptr != cmd)
			{
				cmd->execute();
			}
			else
			{
				std::cout << "Unsupported command!" << std::endl;
			}	
		}
	}
};

#endif //MAZEPROJECT_COMMAND_H
