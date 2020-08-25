//
// Created by Sapir Ezra on 24/08/2020.
//

#pragma once


#include "Maze2d.h"
#include "Model.h"
#include <string>
#include "Solution.h"

//Class View is responsible for the input from the user, and for displaying the interface
class View
{
public:
	View(){}
	virtual void display(Maze2d &maze)=0;
	virtual void showMsg(std::string s)=0;
	virtual void displaySolution(Maze2d& maze, Solution<Position>& solution) = 0;
	

};

