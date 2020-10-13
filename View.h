

#pragma once


#include "Maze2d.h"
#include "Model.h"
#include <string>
#include "Solution.h"
#include "CLI.h"
#include "Controller.h"

//Class View is responsible for the input from the user, and for displaying the interface
class View
{
	public:
	virtual void display(Maze2d &maze)=0;
	virtual void showMsg(std::string s)=0;
	virtual void displaySolution(Maze2d& maze, Solution<Position>& solution) = 0;
	virtual void start(std::shared_ptr<Controller> c)=0;
	

};

