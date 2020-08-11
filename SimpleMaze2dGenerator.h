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
    void solve(Maze2d& maze); //check what the function needs to return
    //how do we keep the path to the goal
};

// class AStar
// {

// };

// class BFS
// {

// };

#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
