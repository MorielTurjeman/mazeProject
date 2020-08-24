//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_OBSERVABLE_H
#define MAZEPROJECT_OBSERVABLE_H
#include "Observer.h"
#include <vector>

class Observable
{
public:
	void addObserver(Observer& observer)
	{
		
	}

private:
	std::vector<Observer*> m_observers;
};


#endif //MAZEPROJECT_OBSERVABLE_H
