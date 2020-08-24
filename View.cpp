//
// Created by Sapir Ezra on 24/08/2020.
//

#include "View.h"
#include "Maze2d.h"

void View::display(Maze2d &maze)
{
//	for(i : )

	for (int i = 0; i < maze.getMaze().size(); i++)
	{
		for (int j = 0; j < maze.getMaze().size(); j++)
		{
			if (maze.getMaze()[i][j] == 1)
				std::cout << "\u2593";

			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
