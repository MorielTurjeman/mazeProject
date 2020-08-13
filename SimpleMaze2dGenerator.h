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


class MyMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size);
};



#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




