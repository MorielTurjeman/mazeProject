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
        
        srand (time(NULL));
        int startWall = rand()%4; //we pick randomly the wall for the start, 0-top wall, 1-right wall, 2-bottom wall, 3-left wall
        //the end position will be at the opposite wall
        
        srand (time(NULL));
        int startIndex = rand()%size; //pick a random index in the wall chosen for start
        srand (time(NULL));
        int endIndex = rand()%size; //pick a random index in the wall chosen for end

        switch (startWall)
        {
        case 0: //start is at the top wall, end is at the bottom
            // endWall=2;
            Position startPosition(startIndex, 0);
            Position endPosition(endIndex, size);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
            break;

        case 1: //the start is at the right wall, end is at the left
            Position startPosition(size, startIndex);
            Position endPosition(0, endIndex);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
            break;

        case 2: //the start is at the bottom wall, the end is a the top
            Position startPosition(startIndex, size);
            Position endPosition(endIndex, 0);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
            break;

        case 3: //the start is at the left wall, the end is at the right
            Position startPosition(0, startIndex);
            Position endPosition(size, endIndex);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
            break;
        
        default:
            break;
        }
        Position startPosition = maze.getStartPosition();
        Position currentPosition = maze.getCurrentPosition();
        Position endPosition = maze.getEndPosition();
        std::vector<Position> possibleMoves = maze.getPossibleMoves(startPosition);
        while (currentPosition != endPosition)
        {
            currentPosition = possibleMoves.pop_back();
        }
        
    }
};


class MyMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size);
};



#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




