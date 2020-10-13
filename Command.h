

#pragma once
#include <memory>
#include <vector>
#include <string>

class Model;
class View;

class Command
{
protected:
	std::shared_ptr<Model> model;
	std::shared_ptr<View> view;

public:
	Command(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : model(myModel), view(view) {}
	virtual void execute(std::ostream &out) = 0;																//pass stdout to update the view
	virtual void setArgs(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end) = 0; //pass stdin to read input
};


class DirCommand : public Command 
{
public:
	DirCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;


private:
	
	std::string _name;
};

/************************************************************************************/

class GenerateMazeCommand : public Command
{
public:
	GenerateMazeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}

	void execute(std::ostream &out) override;


	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	

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
	DisplayCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	

private:
	std::string _name;
};

/************************************************************************************/

class SaveMazeCommand : public Command
{
public:
	SaveMazeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	

private:
	std::string _name;
	std::string _fileName;
};

/************************************************************************************/
class LoadMazeCommand : public Command
{
public:
	LoadMazeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;


private:
	std::string _name;
	std::string _fileName;
};

/************************************************************************************/

class MazeSizeCommand : public Command
{
public:
	MazeSizeCommand (std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	
	void execute(std::ostream &out) override;

	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	
private:
	std::string _name;
};

/************************************************************************************/

class FileSizeCommand : public Command
{
public:
	FileSizeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	
private:
	std::string _name;
};

/************************************************************************************/

class SolveCommand : public Command
{
public:
	SolveCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;

	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	

private:
	std::string _name;
	std::string _mazeSolutionAlgorithm;
	std::string _h;
};

/************************************************************************************/

class DisplaySolutionCommand : public Command
{
public:
	DisplaySolutionCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}

	void execute(std::ostream &out) override;

	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	

private:
	std::string _name;
};

/************************************************************************************/

class ExitCommand : public Command // todo: decide if we need it
{
public:
	ExitCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override
	{
		exit(0);
	}
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override
	{}
};
