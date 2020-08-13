//
// Created by Sapir Ezra on 11/08/2020.
//

#ifndef MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#define MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#include "Maze2dGenerator.h"
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size)
    {
        Maze2d maze(size);
        //the start position will be picked randomly from any index in the top wall or the left wall of the maze
        srand (time(NULL));
        int startWall = rand()%2; //0 for top wall, 1 for left wall
        srand (time(NULL));
        int endWall = rand()%2; //0 for bottom wall, 1 for right wall
        srand (time(NULL));
        int startIndex = rand()%size; //pick an index in the wall chosen for start
        srand (time(NULL));
        int endIndex = rand()%size; //pick an index in the wall chosen for end

        

        if (startWall) //if the start is at the left wall
        {
            Position startPosition(0, startIndex);
            maze.setStartPosition(startPosition);
        }
        else //if the end is at the top wall
        {
            Position startPosition(startIndex, 0);
            maze.setStartPosition(startPosition);
        }
        if (endWall) //if the end is at the right wall
        {
            Position endPosition(size, endIndex);
        }
        else //if the end is at the bottom wall
        {
            Position endPosition(endIndex, size);
        }
        
        
        
        
        

    }
};


class MyMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size);
};



#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




