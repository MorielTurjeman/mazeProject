#pragma once

#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include <random>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class MyMaze2dGenerator : public Maze2dGeneratorAbs
{
public:
    ~MyMaze2dGenerator() {}
    virtual Maze2d generate(int size)
    {
       
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, size - 1);
        int row = distribution(generator); //y
        int col = distribution(generator); //x
        //r[row][col]=>is actually (y,x)

        Position start{col, row};
        std::stack<Position> stack;
        std::vector<Position> visited;
        stack.push(start);
        Maze2d maze(size);

        while (!stack.empty())
        {
            Position p = stack.top(); // p is the parent
            stack.pop();
            if (std::find(visited.begin(), visited.end(), p) != visited.end())
                continue; // if already visited
            visited.push_back(p);
            auto pMoves = maze.getPossibleMoves(p); // the parents possible moves

            if (!pMoves.empty())
            {

                auto randPMovesIdx = distribution(generator) % pMoves.size(); // choose rand node and remove the wall
                stack.push(pMoves[randPMovesIdx]);

                maze.removeWall(pMoves[randPMovesIdx]);

                for (int i = 0; i < pMoves.size(); i++)
                {
                    stack.push(pMoves[i]);
                    if (pMoves[i] != pMoves[randPMovesIdx])
                    {
                        visited.push_back(pMoves[i]);
                    }
                }
            }
        }

    }

private:
   
};