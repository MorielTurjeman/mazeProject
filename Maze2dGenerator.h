//
// Created by Sapir Ezra on 11/08/2020.
//

#ifndef MAZEPROJECT_MAZE2DGENERATOR_H
#define MAZEPROJECT_MAZE2DGENERATOR_H
#include "Maze2d.h"
#include <string>


class Maze2dGenerator
{
public:
    virtual Maze2d generate(int size)=0;

    virtual std::string measureAlgorithmTime()=0;


};

class Maze2dGeneratorAbs : public Maze2dGenerator
{
    virtual Maze2d generate(int size)=0;
    virtual std::string measureAlgorithmTime();
};


#endif //MAZEPROJECT_MAZE2DGENERATOR_H
