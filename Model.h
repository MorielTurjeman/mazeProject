//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once

#include <unordered_map>
#include "Maze2d.h"
#include "Solution.h"
#include <string>


class Model
{
public:
	virtual void saveMazeToCache(Maze2d& m)=0;
	virtual Solution<Position> checkIfSolutionIsInCacheMap(std::string name) = 0;
	virtual Maze2d getMaze(std::string name) = 0;
	// {
	// 	for(const std::pair<std::string, Solution<Position>> &val : solutionCacheMap)
	// 	{
	// 		if (val.first == name)
	// 		{
	// 			return val.second;
	// 		}
	// 	}
	// 	return NULL;
	// }

private:
	std::unordered_map<std::string, Solution<Position>> solutionCacheMap;
};

