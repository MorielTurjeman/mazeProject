//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYMODEL_H
#define MAZEPROJECT_MYMODEL_H
#include "Model.h"

class MyModel : public Model
{	//todo:	
public:
	virtual void saveMazeToCache(Maze2d& m){
		
	}
	virtual shared_ptr<Solution<Position>> checkIfSolutionIsInCacheMap(std::string name);
	virtual std::shared_ptr<Maze2d> getMaze(std::string name) ;

};


#endif //MAZEPROJECT_MYMODEL_H
