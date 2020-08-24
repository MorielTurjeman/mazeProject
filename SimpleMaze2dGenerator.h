//
// Created by Sapir Ezra on 11/08/2020.
//

#ifndef MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#define MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
#include "Maze2dGenerator.h"
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <random>

class SimpleMaze2dGenerator : public Maze2dGeneratorAbs
{
public:
    SimpleMaze2dGenerator(){};
    ~SimpleMaze2dGenerator() {}
    virtual Maze2d generate(int size)
    {
        Maze2d maze(size);
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, 4); // random move
        Position start = maze.randomWallPosition();
        for (int i = 0; i < size; i++) // set the frame
        {
            maze.getMaze()[i][0] = 1;
            maze.getMaze()[i][size - 1] = 1;
            maze.getMaze()[0][i] = 1;
            maze.getMaze()[size - 1][i] = 1;
        }

        maze.setStartPosition(start);
        Position p = start;
        std::vector<Position> visited;
        for(int count = 0; ; count++)
        {
            visited.push_back(p);

            std::vector<Position> pMoves = maze.getPossibleMoves(p);

            for (int i = pMoves.size() - 1; i >= 0; i--)
            {
                if (std::find(visited.begin(), visited.end(), pMoves[i]) != visited.end())
                    pMoves.erase(pMoves.begin() + i);
            }

            int idx = distribution(generator) % pMoves.size();
            p = pMoves[idx];
            if (count < size /2)
            {
                continue;
            }
            if (p.getXPosition() == 1)
            {
                visited.push_back(p);
                Position end=  {0, p.getYPosition()};
                visited.push_back(end);
                break;
            }
            else if (p.getXPosition() == size - 2)
            {
                visited.push_back(p);
                
                Position end=  {size-1, p.getYPosition()};
                visited.push_back(end);
                break;
            }
            else if (p.getYPosition() == size - 2)
            {
                visited.push_back(p);
                
                Position end=  {p.getXPosition(), size-1};
                visited.push_back(end);
                break;
            }
            else if (p.getYPosition() == 1)
            {
                visited.push_back(p);
                
                Position end=  {p.getXPosition(), 0};
                visited.push_back(end);
                break;
            }

            // if (p.getXPosition() == size - 1 || p.getYPosition() == size - 1 || p.getXPosition() == 0 || p.getYPosition() == 0)
            // {
            //     maze.setEndPosition(p);
            //     visited.push_back(p);
            //     break;
            // }
        }

        std::uniform_int_distribution<int> randomOneOrZero(0, 1);
        for (int i = 1; i < (maze.getMaze().size()-1); i++)
        {
            for (int j = 1; j < (maze.getMaze()[i].size()-1); j++)
            {
                if (maze.getMaze()[i][j] != 2)
                {
                    int randomWallOrPassage = randomOneOrZero(generator);
                    maze.getMaze()[i][j] = randomWallOrPassage; //pick randomly, 1 for wall, 0 for passage
                }
            }
        }


        for (int i = 0; i < visited.size(); i++)
        {
            // std::cout<<visited[i].getXPosition()<<","<<visited[i].getYPosition()<<std::endl;
            maze.getMaze()[visited[i].getYPosition()][visited[i].getXPosition()] = 0;
        }

        return maze;

        // Position end= maze.randomWallPosition();
        // maze.setEndPosition(end);
        // Position start = maze.randomWallPosition();
        // maze.setStartPosition(start);

        // we pick randomly the wall for the start, 0-top wall, 1-right wall, 2-bottom wall, 3-left wall
        // the end position will be at the opposite wall

        // std::random_device                  rand_dev;
        // std::mt19937                        generator(rand_dev());
        // std::uniform_int_distribution<int>  distr(0, 3);

        // int startWall = distr(generator);
        // std::cout << "start wall is:" << startWall <<std::endl;

        // std::uniform_int_distribution<int>  randomIndex(0, size-1);
        // int startIndex = randomIndex(generator); //pick a random index in the wall chosen for start
        // std::cout << "start index is: "<< startIndex <<std::endl;

        // int endIndex = randomIndex(generator); //pick a random index in the wall chosen for end
        // std::cout << "end index is: " << endIndex <<std::endl;

        // if (startWall==0) //start is at the top wall, end is at the bottom
        // {
        //     Position startPosition(startIndex, 0);
        //     Position endPosition(endIndex, size-1);
        //     maze.setStartPosition(startPosition);
        //     maze.setCurrentPosition(startPosition);
        //     maze.setEndPosition(endPosition);
        // }
        // if (startWall==1) //the start is at the right wall, end is at the left
        // {
        //     Position startPosition(size-1, startIndex);
        //     Position endPosition(0, endIndex);
        //     maze.setStartPosition(startPosition);
        //     maze.setCurrentPosition(startPosition);
        //     maze.setEndPosition(endPosition);
        // }
        // if (startWall==2) //the start is at the bottom wall, the end is a the top
        // {
        //     Position startPosition(startIndex, size-1);
        //     Position endPosition(endIndex, 0);
        //     maze.setStartPosition(startPosition);
        //     maze.setCurrentPosition(startPosition);
        //     maze.setEndPosition(endPosition);
        // }
        // if (startWall==3) //the start is at the left wall, the end is at the right
        // {
        //     Position startPosition(0, startIndex);
        //     Position endPosition(size-1, endIndex);
        //     maze.setStartPosition(startPosition);
        //     maze.setCurrentPosition(startPosition);
        //     maze.setEndPosition(endPosition);
        // }

        // Position startPosition = maze.randomWallPosition();
        // maze.setStartPosition(startPosition);
        // std::cout << "Start position is: " << startPosition.getXPosition() << ", " << startPosition.getYPosition() <<std::endl;

        // Position currentPosition = maze.getStartPosition();
        // Position endPosition = maze.randomWallPosition();
        // maze.setEndPosition(endPosition);
        // std::cout << "End position is: " << endPosition.getXPosition() << ", " << endPosition.getYPosition() <<std::endl;

        // std::vector<Position> possibleMoves = maze.getPossibleMoves(startPosition);

        // std::uniform_int_distribution<int>  randomMove(0, possibleMoves.size()-1);
        // std::vector<Position> visited;
        // while (currentPosition != endPosition)
        // {
        //     visited.push_back(currentPosition);
        //     // maze.printMaze();
        //     maze.getMaze()[currentPosition.getYPosition()][currentPosition.getXPosition()] = 2;
        //     int randomMoveIndex=randomMove(generator);
        //     currentPosition = possibleMoves.at(randomMoveIndex); //pick a possible move randomly from the vector of possible moves
        //     possibleMoves = maze.getPossibleMoves(currentPosition);
        // }

        // std::uniform_int_distribution<int>  randomOneOrZero(0, 1);
        // for (int i = 1; i < (maze.getMaze().size()-1); i++)
        // {
        //     for (int j = 1; j < (maze.getMaze()[i].size()-1); j++)
        //     {
        //         // if (maze.getMaze()[i][j]!= 2)
        //         // {
        //             int randomWallOrPassage = randomOneOrZero(generator);
        //             maze.getMaze()[i][j] = randomWallOrPassage; //pick randomly, 1 for wall, 0 for passage
        //         // }

        //     }
        // }

        // for(auto p : visited)
        // {
        //     std::cout << p.getXPosition() << ", " << p.getYPosition() << std::endl;
        //     maze.getMaze()[p.getYPosition()][p.getXPosition()] = 0;
        // }

        // for (int i = 0; i < size; i++)
        // {
        //     for (int j = 0; j < size; j++)
        //     {
        //         if (maze.getMaze()[i][j] == 2)
        //         {
        //             maze.getMaze()[i][j] = 0; //mark the path to the goal as a passage
        //         }
        //     }
        // }
        // maze.getMaze().at(startPosition.getXPosition()).at(startPosition.getYPosition())=2;
        // maze.getMaze().at(endPosition.getXPosition()).at(endPosition.getYPosition())=3;
        // maze.printMaze();

        return maze;
    }
};

#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
