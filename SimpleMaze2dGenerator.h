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
#include <vector>

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{
public:
    SimpleMaze2dGenerator()=default;
    ~SimpleMaze2dGenerator(){}
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

        if (startWall==0) //start is at the top wall, end is at the bottom
        {
            Position startPosition(startIndex, 0);
            Position endPosition(endIndex, size-1);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
        }
        if (startWall==1) //the start is at the right wall, end is at the left
        {
            Position startPosition(size-1, startIndex);
            Position endPosition(0, endIndex);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
        }
        if (startWall==2) //the start is at the bottom wall, the end is a the top
        {
            Position startPosition(startIndex, size-1);
            Position endPosition(endIndex, 0);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
        }
        if (startWall==3) //the start is at the left wall, the end is at the right
        {
            Position startPosition(0, startIndex);
            Position endPosition(size-1, endIndex);
            maze.setStartPosition(startPosition);
            maze.setCurrentPosition(startPosition);
            maze.setEndPosition(endPosition);
        }
        
        // switch (startWall)
        // {
        // case 0: //start is at the top wall, end is at the bottom
            
        //     break;

        // case 1: //the start is at the right wall, end is at the left
            
        //     break;

        // case 2: //the start is at the bottom wall, the end is a the top
            
        //     break;

        // case 3: //the start is at the left wall, the end is at the right
            
        //     break;
        
        // default:
        //     break;
        // }
        Position startPosition = maze.getStartPosition();
        Position currentPosition = maze.getCurrentPosition();
        Position endPosition = maze.getEndPosition();
        std::vector<Position> possibleMoves = maze.getPossibleMoves(startPosition);

        //we go randomly from start position to end position
        //since the board is currently all 0's, we mark the path with 2's.
        //then we randomly place walls (marked as 1's) and passages (marked by 0's)
        //you can walk where there are passages, but not where there are walls
        //the path to the goal (marked with 2's) will be changed after the random walls were placed to 0's
        while (currentPosition != endPosition)
        {
            maze.getMaze()[currentPosition.getXPosition()][currentPosition.getYPosition()] = 2;
            srand (time(NULL));
            currentPosition = possibleMoves[rand()%possibleMoves.size()]; //pick a possible move randomly from the vector of possible moves
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (maze.getMaze()[i][j] != 2)
                {
                    srand (time(NULL));
                    maze.getMaze()[i][j] = rand()%2; //pick randomly, 1 for wall, 0 for passage
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (maze.getMaze()[i][j] == 2)
                {
                    maze.getMaze()[i][j] = 0; //mark the path to the goal as a passage
                }
            }
        }
        return maze;
    }
    
};


class MyMaze2dGenerator : public Maze2dGeneratorAbs
{
    virtual Maze2d generate(int size);
};





#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H




