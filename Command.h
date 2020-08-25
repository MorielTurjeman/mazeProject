//
// Created by Sapir Ezra on 23/08/2020.
//

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
	// {;
	// 	std::string path = "/path/to/directory";
	// 	for (const auto &entry : fs::directory_iterator(path))
	// 		view.showMsg(entry.path().filename().string());
	// }

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end)
	// 	{
	// 		_name = *start;

	// 	}
	// 	else
	// 		view.showMsg("Invalid Parameters");
	// }

private:
	
	std::string _name;
};

/************************************************************************************/

class GenerateMazeCommand : public Command
{
public:
	GenerateMazeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}

	void execute(std::ostream &out) override;
	// {
	// 	std::shared_ptr<Maze2dGenerator> generator;
	// 	if (_mazeGenerationAlgorithm == "DFS")				   //
	// 		generator = std::make_shared<MyMaze2dGenerator>(); //MyMaze2dGenerator maze;
	// 	else if (this->_mazeGenerationAlgorithm == "SimpleMaze")
	// 		generator = std::make_shared<SimpleMaze2dGenerator>();

	// 	auto m = generator->generate(_size);
	// 	m.setMazeName(_name);
	// 	model.saveMazeToCache(std::make_shared<Maze2d>(m));

	// 	view.showMsg("Maze " + _name + "is ready");
	// 	//todo: add error msg
	// }

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end)
	// 	{
	// 		_name = *start;
	// 		_size = stoi(*(start + 1));
	// 		_mazeGenerationAlgorithm = (*(start + 2));
	// 	}
	// 	else
	// 		view.showMsg("Invalid Parameters");
	// }

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
	// {
	// 	auto m = model.getMaze(_name);
	// 	if (m == nullptr)
	// 	{
	// 		view.showMsg("Maze named " + _name + " not found");
	// 	}
	// 	view.display(*m);
	// }
	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end) //we only have one param, no need for loop.
	// 		_name = *start;

	// 	else
	// 		view.showMsg("Invalid Parameters");
	// }

private:
	std::string _name;
};

/************************************************************************************/

class SaveMazeCommand : public Command
{
public:
	SaveMazeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	// {
	// 	auto m = model.getMaze(_name);
	// 	if (m == nullptr)
	// 	{
	// 		view.showMsg("Maze named " + _name + " not found");
	// 	}

	// 	MazeCompression mc;
	// 	std::ofstream file(_fileName);
	// 	if (mc.writeToFile(file, *m) == true)
	// 	{
	// 		view.showMsg("Maze compressed into: " + _fileName + " Successfully");
	// 	}

	// 	else
	// 	{
	// 		view.showMsg("Could not save maze");
	// 	}
	// }

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end)
	// 	{
	// 		_name = *start;
	// 		_fileName = (*(start + 1));
	// 	}
	// 	else
	// 		view.showMsg("Invalid Parameters");
	// }

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
	// {
	// 	MazeCompression mc;
	// 	std::ifstream file(_fileName);
		
	// 	std::shared_ptr<Maze2d> m = mc.readFromFile(file);
	// 	if (m != nullptr)
	// 	{	
	// 		m->setMazeName(_name);
	// 		model.saveMazeToCache(m);
	// 		view.showMsg("Maze read from: " + _fileName + " Successfully");

	// 	}

	// 	else
	// 	{
	// 		view.showMsg("Could not load maze");
	// 	}
	// }

	virtual void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {

	// 	if (start != end)
	// 	{
	// 		_name = *start;
	// 		_fileName = (*(start + 1));
	// 	}
	// 	else
	// 		view.showMsg("Invalid Parameters");
	// }

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
	// {
	// 	auto maze = Command::model.getMaze(_name);
	// 	if (maze == NULL)
	// 	{
	// 		view.showMsg("Maze not found. \n");
	// 		return;
	// 	}
	// 	//size of data members:
	// 	auto _sizeOfMazeVector = sizeof(int)*(maze->getMaze().size()* maze->getMaze().size());
	// 	auto _sizeOfStartEndCurrentPosition = sizeof(Position)*3;
	// 	auto _sizeOfMazeName = maze->getMazeName().size();
	// 	auto _sumOfMazeSize = _sizeOfMazeVector + _sizeOfStartEndCurrentPosition + _sizeOfMazeName;
	// 	view.showMsg("Size of " + _name + "in memory is: " + std::to_string(_sumOfMazeSize) + "bytes of memory.");
	// }
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end) //we only have one param, no need for loop.
	// 	{
	// 		_name = *start;
	// 	}

	// }
private:
	std::string _name;
};

/************************************************************************************/

class FileSizeCommand : public Command
{
public:
	FileSizeCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	// {
	// 	std::ifstream _infile;
	// 	_infile.open(_name, std::ios::in | std::ios::binary);
	// 	_infile.seekg(0, std::ios::end);
	// 	view.showMsg("Size of " + _name + "in file is: " + std::to_string(_infile.tellg()) + "bytes of memory.");
	// }
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end) //we only have one param, no need for loop.
	// 	{
	// 		_name = *start;
	// 	}

	// }
private:
	std::string _name;
};

/************************************************************************************/

class SolveCommand : public Command
{
public:
	SolveCommand(std::shared_ptr<Model> myModel, std::shared_ptr<View> view) : Command(myModel, view) {}
	void execute(std::ostream &out) override;
	// {
	// 	shared_ptr<Maze2d> _maze = Command::model.getMaze(_name);
	// 	if (_maze == NULL)
	// 	{
	// 		view.showMsg("Maze not found. \n");
	// 		return;
	// 	}
	// 	Maze2dSearchable s(*_maze);

	// 	if(this->_mazeSolutionAlgorithm == "BFS" || _mazeSolutionAlgorithm == "bfs")
	// 	{
	// 		BFS<Position> bfs;
	// 		auto solBFS = bfs.search(s);
	// 		view.showMsg("Solution for " + _name + "is ready");
	// 		for (auto p : solBFS.getPath())
	// 		{
	// 			view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
	// 		}
	// 	}
	// 	if(this->_mazeSolutionAlgorithm == "AStar arial" || this->_mazeSolutionAlgorithm == "A* arial")
	// 	{
	// 		AerialDistance ad(s.getGoalState());
	// 		AStar<Position> Arialdis(ad);
	// 		auto solAerial = Arialdis.search(s);
	// 		view.showMsg("Solution for " + _name + "is ready");
	// 		for (auto p : solAerial.getPath())
	// 		{
	// 			view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
	// 		}
	// 	}
	// 	if(this->_mazeSolutionAlgorithm == "AStar Manhattan" || this->_mazeSolutionAlgorithm == "A* Manhattan")
	// 	{
	// 		ManhattanDistance amd(s.getGoalState());
	// 		AStar<Position> manhattendis(amd);
	// 		auto solManhattan = manhattendis.search(s);
	// 		view.showMsg("Solution for " + _name + "is ready");
	// 		for (auto p : solManhattan.getPath())
	// 		{
	// 			view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
	// 		}
	// 	}
	// }
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end)
	// 	{
	// 		_name = *start;
	// 		_mazeSolutionAlgorithm = *(start + 1);
	// 	}
	// }

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
	// {
	// 	auto sol = Command::model.checkIfSolutionIsInCacheMap(_name);
	// 	if (sol == nullptr)
	// 	{
	// 		view.showMsg("Solution for " + _name + "not found. \n");
	// 		return;
	// 	}
	// 	for (auto p : sol->getPath())
	// 	{
	// 		view.showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
	// 	}
	// }
	void setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) override;
	// {
	// 	if (start != end) //we only have one param, no need for loop.
	// 	{
	// 		_name = *start;
	// 	}
	// }

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
