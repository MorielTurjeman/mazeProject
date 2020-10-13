

#ifndef MAZEPROJECT_OBSERVER_H
#define MAZEPROJECT_OBSERVER_H
#include "Observable.h"


class Observable;
class Observer
{
public:
	virtual void update(Observable &observable) = 0;
};


#endif //MAZEPROJECT_OBSERVER_H
