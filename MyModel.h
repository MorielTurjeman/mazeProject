//
// Created by Sapir Ezra on 23/08/2020.
//

#ifndef MAZEPROJECT_MYMODEL_H
#define MAZEPROJECT_MYMODEL_H
#include <map>
#include "Maze2d.h"
#include "Solution.h"

class MyModel
{
	std::map<Maze2d, Solution<Position>> solutionCache;
};


#endif //MAZEPROJECT_MYMODEL_H
