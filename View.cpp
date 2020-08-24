//
// Created by Sapir Ezra on 24/08/2020.
//

#include "View.h"

void View::display(Maze2d &maze)
{
//	for(i : )

	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze.size(); j++)
		{
			if (maze[i][j] == 1)
				std::cout << "\u2593";

			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
