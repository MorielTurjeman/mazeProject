//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYMODEL_H
#define MAZEPROJECT_MYMODEL_H
#include "Model.h"

class MyModel : public Model
{	//todo:	
public:
	virtual void saveMazeToCache(Maze2d& m)=0;//implemnt needed here for everything!!!!!!!!!!!!!!!!!!!!!! not pure virtual
	virtual shared_ptr<Solution<Position>> checkIfSolutionIsInCacheMap(std::string name);
	virtual Maze2d getMaze(std::string name) = 0;
	virtual shared_ptr<Maze2d> checkIfMazeIsInCacheMap(std::string name);

};


#endif //MAZEPROJECT_MYMODEL_H
