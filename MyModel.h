//
// Created by Sapir Ezra on 24/08/2020.
//
#pragma once

#include "Model.h"

class MyModel : public Model
{ //todo:
public:
	virtual void saveMazeToCache(std::shared_ptr<Maze2d> &m)
	{
		mazeNameCacheMap[m->getMazeName()] = m;
	}

	virtual shared_ptr<Solution<Position>> checkIfSolutionIsInCacheMap(std::string name)//todo
	{
		return solutionCacheMap[name];
	}
	virtual std::shared_ptr<Maze2d> getMaze(std::string name){
		 return mazeNameCacheMap[name]; 
	}


protected:
	std::unordered_map<std::string, shared_ptr<Solution<Position>>> solutionCacheMap;
	std::unordered_map<std::string, shared_ptr<Maze2d>> mazeNameCacheMap;
};

