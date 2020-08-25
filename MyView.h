#pragma once
#include "View.h"
#include "CLI.h"

class MyView : public View
{
public:
    MyView (CLI& cli): cli(cli){};

    virtual void display(Maze2d &maze)//todo: need to implement
    {
        cli.getout()<<maze<<std::endl;
    }

	virtual void showMsg(std::string s) //todo: cout msg to the screen
    {
        cli.getout()<<s<<std::endl;
    }

    virtual void displaySolution(Maze2d& maze, Solution<Position>& solution)
    {
         
    }
private:
    CLI cli;
};



