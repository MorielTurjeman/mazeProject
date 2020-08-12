//
// Created by Sapir Ezra on 11/08/2020.
//

#ifndef MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#define MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#include "Maze2dGenerator.h"
#include <queue>

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size);
};


class MyMaze2dGenerator : public Maze2dGenerator
{
    virtual Maze2d generate(int size);
};

//class Searcher represents algorithms that solve problems by searching
class Searcher
{
    virtual void search(Searchable& searchable)=0; //check what the function needs to return
    //how do we keep the path to the goal
};

class AbstractBlaBlaSearcher : public Searcher
{
    virtual void priorityFunction() = 0; // i dont know what parameters should be here
    virtual void search(Searchable& searchable) {
        //here you have to combined logic of BFS and ASTAR
    }

}

class BFS : public Searcher
{
    virtual void priorityFunction(); // i dont know what parameters should be here
};


class AStar : public BFS
{
    virtual void priorityFunction(); // i dont know what parameters should be here
};


#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




