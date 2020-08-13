#pragma once

#include "Searcable.h"
#include "Maze2d.h"

//class Searcher represents algorithms that solve problems by searching
class Searcher
{
    virtual void search(Searchable& searchable)=0; //check what the function needs to return
    //how do we keep the path to the goal
};

//commonly, search algorithms have a priority queue for evaluating the next best option to go to
class CommonSearcher : public Searcher
{
    virtual void priorityFunction() = 0; // i dont know what parameters should be here
    virtual void search(Searchable& searchable) {
        //here you have to combined logic of BFS and ASTAR
    }

};

class BFS : public CommonSearcher
{
    virtual void priorityFunction(); // i dont know what parameters should be here
};


class AStar : public CommonSearcher
{
    virtual void priorityFunction(); // i dont know what parameters should be here
};
