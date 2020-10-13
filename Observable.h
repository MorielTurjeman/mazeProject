

#ifndef MAZEPROJECT_OBSERVABLE_H
#define MAZEPROJECT_OBSERVABLE_H
#include "Observer.h"
#include <vector>

class Observer;
class Observable
{
public:
	void addObserver(Observer& observer)
	{
		m_observers.push_back(&observer);
	}
	void notify()
	{
		for(auto it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			// (*it)->update(*this);
		}
	}

private:
	std::vector<Observer*> m_observers;
};


#endif //MAZEPROJECT_OBSERVABLE_H
