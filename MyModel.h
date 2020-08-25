//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYMODEL_H
#define MAZEPROJECT_MYMODEL_H
#include "Model.h"

class MyModel : public Model
{	//todo:	
public:
	virtual void saveMazeToCache(std::shared_ptr<Maze2d> maze)=0;//implemnt needed here for everything!!!!!!!!!!!!!!!!!!!!!! not pure virtual
	virtual shared_ptr<Solution<Position>> checkIfSolutionIsInCacheMap(std::string name)=0;
	virtual std::shared_ptr<Maze2d> getMaze(std::string name) = 0;

protected:
	std::unordered_map<std::string, shared_ptr<Maze2d>> _mazeNameCacheMap;
};


#endif //MAZEPROJECT_MYMODEL_H
