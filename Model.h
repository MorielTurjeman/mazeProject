//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once

#include <unordered_map>
#include "Maze2d.h"
#include "Solution.h"

class Model
{
public:
	Solution<Position> checkIfSolutionIsInCacheMap(std::string name)
	{
		for(const std::pair<std::string, Solution<Position>> &val : solutionCacheMap)
		{
			if (val.first == name)
			{
				return val.second;
			}
		}
		return NULL;
	}

private:
	std::unordered_map<std::string, Solution<T>> solutionCacheMap;
};


