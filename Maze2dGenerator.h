//
// Created by Sapir Ezra on 11/08/2020.
//

#ifndef MAZEPROJECT_MAZE2DGENERATOR_H
#define MAZEPROJECT_MAZE2DGENERATOR_H
#include "Maze2d.h"
#include <string>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> //for measureAlgorithmTime


class Maze2dGenerator
{
public:
    Maze2dGenerator(int size){}
    
    virtual Maze2d generate(int size)=0;

    virtual std::string measureAlgorithmTime()=0;


};

class Maze2dGeneratorAbs : public Maze2dGenerator
{
    virtual Maze2d generate(int size)=0;
    virtual std::string measureAlgorithmTime(int size)
    {
        time_t start_time = time(NULL); 
        ctime(&start_time);
        this->generate(size);
        time_t end_time = time(NULL); 
        ctime(&end_time);
        std::string timeMeasured;

        //implement substraction

        return timeMeasured;
    }

};



#endif //MAZEPROJECT_MAZE2DGENERATOR_H
