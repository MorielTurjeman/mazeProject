//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYMODEL_H
#define MAZEPROJECT_MYMODEL_H
#include "Model.h"

class MyModel : public Model
{ //todo:
public:
	virtual void saveMazeToCache(Maze2d &m)
	{
		mazeNameCacheMap[m.getMazeName()] = std::make_shared<Maze2d>(m);
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

#endif //MAZEPROJECT_MYMODEL_H
