//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_DEMO_H
#define MAZEPROJECT_DEMO_H
#include "MyMaze2dGenerator.h"


class Demo
{
public:
	void run(int size)
	{
		Maze2dGeneratorAbs* _maze = new MyMaze2dGenerator;
		_maze->generate(size);

	}
};


#endif //MAZEPROJECT_DEMO_H
