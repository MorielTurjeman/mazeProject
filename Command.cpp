

#include "Command.h"
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
#include <filesystem>
namespace fs = std::filesystem;
#include "Searcher.h"
#include "Maze2dSearchable.h"
#include "MazeCompression.h"
#include "View.h"


	void DirCommand:: execute(std::ostream &out) 
	{
		std::string path = _name;
		for (const auto &entry : fs::directory_iterator(path))
			view->showMsg(entry.path().filename().string());
	}

	 void DirCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end)
		{
			_name = *start;

		}
		else
			view->showMsg("Invalid Parameters");
	}

/

	void GenerateMazeCommand::execute(std::ostream &out) 
	{
		std::shared_ptr<Maze2dGenerator> generator;
		if (_mazeGenerationAlgorithm == "DFS")				   //
			generator = std::make_shared<MyMaze2dGenerator>(); //MyMaze2dGenerator maze;
		else if (this->_mazeGenerationAlgorithm == "SimpleMaze")
			generator = std::make_shared<SimpleMaze2dGenerator>();

		auto m = generator->generate(_size);
		m.setMazeName(_name);
		model->saveMazeToCache(std::make_shared<Maze2d>(m));

		view->showMsg("Maze " + _name + " is ready");
		//todo: add error msg
	}

	 void GenerateMazeCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end)
		{
			_name = *start;
			_size = stoi(*(start + 1));
			_mazeGenerationAlgorithm = (*(start + 2));
		}
		else
			view->showMsg("Invalid Parameters");
	}


	void DisplayCommand::execute(std::ostream &out) 
	{
		auto m = model->getMaze(_name);
		if (m == nullptr)
		{
			view->showMsg("Maze named " + _name + " not found");
			return;
		}
		view->display(*m);
	}
	 void DisplayCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end) //we only have one param, no need for loop.
			_name = *start;

		else
			view->showMsg("Invalid Parameters");
	}


	void SaveMazeCommand::execute(std::ostream &out) 
	{
		auto m = model->getMaze(_name);
		if (m == nullptr)
		{
			view->showMsg("Maze named " + _name + " not found");
			return;
		}

		MazeCompression mc;
		std::ofstream file(_fileName);
		if (mc.writeToFile(file, *m) == true)
		{
			view->showMsg("Maze compressed into: " + _fileName + " Successfully");
		}

		else
		{
			view->showMsg("Could not save maze");
		}
	}

	 void SaveMazeCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end)
		{
			_name = *start;
			_fileName = (*(start + 1));
		}
		else
			view->showMsg("Invalid Parameters");
	}


	void LoadMazeCommand::execute(std::ostream &out) 
	{
		MazeCompression mc;
		
		std::ifstream file(_fileName);
		
		if (!file.is_open())		
		{
			view->showMsg("Can't load file");
			return;
		}
		std::shared_ptr<Maze2d> m = mc.readFromFile(file);
		
		if (m != nullptr)
		{	
			m->setMazeName(_name);
			model->saveMazeToCache(m);
			view->showMsg("Maze read from: " + _fileName + " Successfully");

		}

		else
		{
			view->showMsg("Could not load maze");
		}
	}

	 void LoadMazeCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{

		if (start != end)
		{
			_fileName = *start;
			_name = *(start + 1);
		}
		else
			view->showMsg("Invalid Parameters");
	}


	
	void MazeSizeCommand::execute(std::ostream &out) 
	{
		auto maze = Command::model->getMaze(_name);
		if (maze == NULL)
		{
			view->showMsg("Maze not found. \n");
			return;
		}
		//size of data members:
		auto _sizeOfMazeVector = sizeof(int)*(maze->getMaze().size()* maze->getMaze().size());
		auto _sizeOfStartEndCurrentPosition = sizeof(Position)*3;
		auto _sizeOfMazeName = maze->getMazeName().size();
		auto _sumOfMazeSize = _sizeOfMazeVector + _sizeOfStartEndCurrentPosition + _sizeOfMazeName;
		view->showMsg("Size of " + _name + "in memory is: " + std::to_string(_sumOfMazeSize) + "bytes of memory.");
	}
	void MazeSizeCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end) //we only have one param, no need for loop.
		{
			_name = *start;
		}

	}

	void FileSizeCommand::execute(std::ostream &out) 
	{
		std::ifstream _infile;
		_infile.open(_name, std::ios::in | std::ios::binary);
		_infile.seekg(0, std::ios::end);
		view->showMsg("Size of " + _name + "in file is: " + std::to_string(_infile.tellg()) + "bytes of memory.");
	}
	void FileSizeCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end) //we only have one param, no need for loop.
		{
			_name = *start;
		}

	}

	void SolveCommand::execute(std::ostream &out) 
	{
		shared_ptr<Maze2d> _maze = Command::model->getMaze(_name);
		if (_maze == NULL)
		{
			view->showMsg("Maze not found. \n");
			return;
		}
		Maze2dSearchable s(*_maze);
		auto cachedSolution = model->checkIfSolutionIsInCacheMap(_name);
		if (cachedSolution != nullptr)
		{
				view->showMsg("Solultion for " + _name + " is ready");
				return;
		}
		std::shared_ptr<CommonSearcher<Position>> alg= nullptr;
		if(this->_mazeSolutionAlgorithm == "BFS")
		{
			alg = std::make_shared<BFS<Position>>(); // BFS<Position> bfs;
			
		}
		if(this->_mazeSolutionAlgorithm == "AStar" && this->_h == "aerial")
		{
			AerialDistance ad(s.getGoalState());
			alg = std::make_shared<AStar<Position>>(ad);
			
		}
		if(this->_mazeSolutionAlgorithm == "AStar" && this->_h == "manhattan")
		{
			ManhattanDistance amd(s.getGoalState());
			alg = std::make_shared<AStar<Position>>(amd);
			
			
		}
		auto sol = alg->search(s);
		view->showMsg("Solultion for " + _name + " is ready");
		model->saveSolutionToCache(_name, std::make_shared<Solution<Position>>(sol));
	}
	void SolveCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end)
		{
			_name = *start;
			_mazeSolutionAlgorithm = *(start + 1);
			if (_mazeSolutionAlgorithm == "AStar")
				_h  = *(start + 2);
		}
	}


	void DisplaySolutionCommand::execute(std::ostream &out) 
	{
		auto sol = Command::model->checkIfSolutionIsInCacheMap(_name);
		if (sol == nullptr)
		{
			view->showMsg("Solution for " + _name + "not found. \n");
			return;
		}
		// for (auto p : sol->getPath())
		// {
			auto m = model->getMaze(_name);
			view->displaySolution(*m, *sol);
			// view->showMsg("Row: " + std::to_string(p->data.getYPosition()) + " , Column: " + std::to_string(p->data.getXPosition()) + "\n");
		// }
	}
	void DisplaySolutionCommand::setArgs(std::vector<std::string>::iterator start, std::vector<std::string>::iterator end) 
	{
		if (start != end) //we only have one param, no need for loop.
		{
			_name = *start;
		}
	}



