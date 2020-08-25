//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once

#include <unordered_map>
#include "Maze2d.h"
#include "Solution.h"
#include <string>
#include<memory>


class Model
{
public:
	virtual void saveMazeToCache(std::shared_ptr<Maze2d> maze)=0;
	virtual shared_ptr<Solution<Position>> checkIfSolutionIsInCacheMap(std::string name)=0;
	virtual shared_ptr<Maze2d> checkIfMazeIsInCacheMap(std::string name)=0;
	virtual std::shared_ptr<Maze2d> getMaze(std::string name) = 0;
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

protected:
	std::unordered_map<std::string, shared_ptr<Solution<Position>>> solutionCacheMap;
	std::unordered_map<std::string, shared_ptr<Maze2d>> mazeNameCacheMap;
};

