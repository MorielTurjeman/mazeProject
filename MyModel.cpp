//
// Created by Sapir Ezra on 24/08/2020.
//

#include "MyModel.h"

shared_ptr<Solution<Position>> MyModel::checkIfSolutionIsInCacheMap(std::string name)
{
	auto it = solutionCacheMap.find(name);
	if (it == solutionCacheMap.end())
	{
		return nullptr;
	}
	return it->second;
}