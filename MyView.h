#pragma once
#include "View.h"
#include "CLI.h"
#include "Solution.h"
#include <algorithm>

class MyView : public View
{
public:
    MyView (CLI& cli): cli(cli){};

    virtual void display(Maze2d &maze)
    {
        cli.getout()<<maze<<std::endl;
    }

	virtual void showMsg(std::string s) // cout msg to the screen
    {
        cli.getout()<<s<<std::endl;
    }

    virtual void displaySolution(Maze2d& maze, Solution<Position>& solution)
    {
        auto _maze = maze.getMaze();
        auto start = maze.getStartPosition();
        auto &out = cli.getout();
        auto sol = solution.getPath();
        
        for (int i = 0; i < _maze.size(); i++)
		{
			for (int j = 0; j < _maze.size(); j++)
			{
                State<Position> p = {{j,i}, 0};
				if (_maze[i][j] == 1)
					out << "\u2593";
                else if (std::find(sol.begin(), sol.end(), std::make_shared<State<Position>>(p)) != sol.end())
                {
                    out << '$';
                }
				else if (i == start.getYPosition() && j == start.getXPosition())
				{
					out << "*";
				}
				else
				{
					out << " ";
				}
			}
			out << "\n";
		}
    }
private:
    CLI cli;
};



