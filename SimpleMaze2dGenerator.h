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

            if (pMoves.size() == 0)
            {
                count = 0;
                visited.resize(0);
                p = start;
                continue;
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
            
            maze.getMaze()[visited[i].getYPosition()][visited[i].getXPosition()] = 0;
        }

        return maze;

   

        return maze;
    }
};

#endif //MAZEPROJECT_SIMPLEMAZE2DGENERATOR_H
