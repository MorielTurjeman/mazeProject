#pragma once

#include "Searcable.h"
#include "Maze2d.h"


//class Searcher represents algorithms that solve problems by searching
class Searcher
{
    virtual void search(Searchable &searchable) = 0; //check what the function needs to return
    //how do we keep the path to the goal
};

//commonly, search algorithms have a priority queue for evaluating the next best option to go to
class CommonSearcher : public Searcher
{
    virtual bool priorityFunction(const State &a, const State &b) = 0;
    virtual void search(Searchable &searchable);

};

class BFS : public CommonSearcher
{
    virtual bool priorityFunction(const State &a, const State &b);
};

class AStar : public CommonSearcher
{
    virtual bool priorityFunction(const State &a, const State &b);
};
