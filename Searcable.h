#pragma once

#include "Maze2d.h"
#include<memory>


//represents a state in a search problem(the position and the distance from root)
template <class T>
class State
{

public:
	T data; //former position
	int cost;
    std::shared_ptr<State<T>> parent;
	bool operator==(const State &other) const
	{
		return (this->data == other->data);
	}
};

/**************************************************************************************/

//class Searchable represents a problem that can be searched, and refers to state only
template <class T>
class Searchable
{
public:
    virtual const std::vector<State<T>> getPossibleStates(State<T> &currState) = 0; // we need to return search state and not position. the vector holds serach states (the tree).
    virtual const State<T> getStartState() = 0;
    virtual const State<T> getGoalState() = 0;
};