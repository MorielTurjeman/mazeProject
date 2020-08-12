//
// Created by Sapir Ezra on 11/08/2020.
//

#ifndef MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#define MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#include "Maze2dGenerator.h"

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size);
};


class MyMaze2dGenerator : public Maze2dGenerator
{
    virtual Maze2d generate(int size);
};

class Solver
{
    virtual void solve(Maze2d& maze); //check what the function needs to return
    //how do we keep the path to the goal
};

class BFS : public Solver
{
    virtual void solve(Maze2d& maze);
};


class AStar : public BFS
{
        void solve(Maze2d& maze)
};


#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




