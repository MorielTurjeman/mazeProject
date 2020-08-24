//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once

#include <unordered_map>
#include "Maze2d.h"
#include "Solution.h"

template<class T>
class MyModel
{
public:
	Solution<T> checkIfSolutionIsInCacheMap(Maze2d& maze)
	{
		for(const std::pair<Maze2d, Solution<T>> &val : solutionCacheMap)
		{
			if (1) //todo
			{

			}
		}
	}


private:
	std::unordered_map<std::string, Solution<T>> solutionCacheMap;
};


