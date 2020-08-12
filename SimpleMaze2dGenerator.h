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

class BFS : public Searcher
{
    virtual void search(Searchable& searchable);
};


class AStar : public BFS
{
    virtual void search(Searchable& searchable);
};


#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




