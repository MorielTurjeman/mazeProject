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

class Searcher
{
<<<<<<< HEAD
    virtual void solve(Maze2d& maze)=0; //check what the function needs to return
=======
    virtual void search(Maze2d& maze)=0; //check what the function needs to return
>>>>>>> ee8cc0e26a6eb0ef1f8dd526f859d78bb2e6f7ad
    //how do we keep the path to the goal
};

class BFS : public Searcher
{
    virtual void search(Maze2d& maze);
};


class AStar : public BFS
{
<<<<<<< HEAD
    virtual void solve(Maze2d& maze);
=======
    virtual void search(Maze2d& maze);
>>>>>>> ee8cc0e26a6eb0ef1f8dd526f859d78bb2e6f7ad
};


#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




