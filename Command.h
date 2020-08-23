//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_COMMAND_H
#define MAZEPROJECT_COMMAND_H
#include <string>


//here we are using the Command design pattern
//the goal is to separate the Invoker of a Command from the Receiver
class Command
{
public:
	virtual void execute()=0;
};

class Dir : public Command
{
public:
	Dir(std::string path): _path(path){}
	void execute() override
	{

	}

private:
	std::string  _path;
};

class GenerateMaze : public Command
{
public:
	GenerateMaze(std::string name, int size, std::string mazeGenerationAlgorithm): _name(name), _size(size), _mazeGenerationAlgorithm(mazeGenerationAlgorithm){}
	void execute() override
	{

	}

private:
	std::string  _name;
	int _size;
	std::string _mazeGenerationAlgorithm;
};

class DisplayMaze : public Command
{
public:
	DisplayMaze(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string _name;
};

class SaveMaze : public Command
{
public:
	SaveMaze(std::string name, std::string fileName): _name(name), _fileName(fileName){}
	void execute() override
	{

	}

private:
	std::string  _name;
	std::string  _fileName;
};

class LoadMaze : public Command
{
public:
	LoadMaze(std::string name, std::string fileName): _name(name), _fileName(fileName){}
	void execute() override
	{

	}

private:
	std::string  _name;
	std::string  _fileName;
};

class MazeSize : public Command
{
public:
	MazeSize(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string  _name;
};

class FileSize : public Command
{
public:
	FileSize(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string  _name;
};

class Solve : public Command
{
public:
	Solve(std::string name, std::string algorithm): _name(name), _algorithm(algorithm){}
	void execute() override
	{

	}

private:
	std::string  _name;
	std::string  _algorithm;
};

class DisplaySolution : public Command
{
public:
	DisplaySolution(std::string name): _name(name){}
	void execute() override
	{

	}

private:
	std::string  _name;
};

class Exit : public Command
{
	Exit(); //todo: check if necessary!!!!!!!!!!!!!!!!!!
	void execute() override
	{
		
	}
};

#endif //MAZEPROJECT_COMMAND_H
