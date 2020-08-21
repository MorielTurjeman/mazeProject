#pragma once

#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <stack>

class MyMaze2dGenerator: public Maze2dGeneratorAbs
{
public:
    MyMaze2dGenerator()=default;
    ~MyMaze2dGenerator(){}
    virtual Maze2d generate(int size)
    {
        Maze2d maze(size);
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(0, size);

        Position startPosition(distr(generator), 0);
        Position endPosition(distr(generator), size-1);
        maze.setStartPosition(startPosition);
        maze.setCurrentPosition(startPosition);
        maze.setEndPosition(endPosition);

        while (!_stack.empty())
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    /* code */
                }
                
            }
            
        }
        

        /*
        Choose the initial cell, mark it as visited and push it to the stack
        While the stack is not empty
            Pop a cell from the stack and make it a current cell
            If the current cell has any neighbours which have not been visited
                Push the current cell to the stack
                Choose one of the unvisited neighbours
                Remove the wall between the current cell and the chosen cell
                Mark the chosen cell as visited and push it to the stack
        */



        /*
        Given a current cell as a parameter,
        Mark the current cell as visited
        While the current cell has any unvisited neighbour cells
            Choose one of the unvisited neighbours
            Remove the wall between the current cell and the chosen cell
            Invoke the routine recursively for a chosen cell
        */ 

        
        
    }

private:
    std::queue<std::vector<int> > _stack;
};