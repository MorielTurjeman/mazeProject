//
// Created by Sapir Ezra on 11/08/2020.
//
#pragma once

#include "Maze2d.h"
#include <string>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> //for measureAlgorithmTime
#include<chrono>


class Maze2dGenerator
{
public:
    Maze2dGenerator(){}
    
    virtual Maze2d generate(int size)=0;

    virtual std::string measureAlgorithmTime(int size)=0;

    ~Maze2dGenerator(){}

};

class Maze2dGeneratorAbs : public Maze2dGenerator
{
public:
    ~Maze2dGeneratorAbs(){}

public:
    virtual Maze2d generate(int size)=0;
    virtual std::string measureAlgorithmTime(int size)
    {
        auto start = std::chrono::system_clock::now();
        this->generate(size);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
	    return std::to_string(elapsed_seconds.count());
    }
};




