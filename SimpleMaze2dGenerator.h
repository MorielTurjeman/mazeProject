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
#include <random>

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{
public:
    SimpleMaze2dGenerator()=default;
    ~SimpleMaze2dGenerator(){}
    virtual Maze2d generate(int size)
    {
        Maze2d maze(size);
        
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(0, 3);

        int startWall = distr(generator);
        std::cout << "start wall is:" << startWall <<std::endl;
        
        std::uniform_int_distribution<int>  randomIndex(0, size-1);
        int startIndex = randomIndex(generator); //pick a random index in the wall chosen for start
        std::cout << "start index is: "<< startIndex <<std::endl;
        
        int endIndex = randomIndex(generator); //pick a random index in the wall chosen for end
        std::cout << "end index is: " << endIndex <<std::endl;

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
        
        Position startPosition = maze.getStartPosition();
        Position currentPosition = maze.getCurrentPosition();
        Position endPosition = maze.getEndPosition();
        std::vector<Position> possibleMoves = maze.getPossibleMoves(startPosition);

        //we go randomly from start position to end position
        //since the board is currently all 0's, we mark the path with 2's.
        //then we randomly place walls (marked as 1's) and passages (marked by 0's)
        //you can walk where there are passages, but not where there are walls
        //the path to the goal (marked with 2's) will be changed after the random walls were placed to 0's
        std::uniform_int_distribution<int>  randomMove(0, possibleMoves.size()-1);
        while (currentPosition != endPosition)
        {
            maze.getMaze()[currentPosition.getXPosition()][currentPosition.getYPosition()] = 2;
            int randomMoveIndex=randomMove(generator);
            currentPosition = possibleMoves[randomMoveIndex]; //pick a possible move randomly from the vector of possible moves
        }

        std::uniform_int_distribution<int>  randomWall(0, 1);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (maze.getMaze()[i][j] != 2)
                {
                    int randomWallOrPassage = randomWall(generator);
                    maze.getMaze()[i][j] = randomWallOrPassage; //pick randomly, 1 for wall, 0 for passage
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




