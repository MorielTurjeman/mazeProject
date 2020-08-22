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
        //https://hurna.io/academy/algorithms/maze_generator/dfs.html
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
            auto pMoves = maze.getPossibleMoves(p, size); // the parents possible moves

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












        // Maze2d maze(size);
        // std::random_device                  rand_dev;
        // std::mt19937                        generator(rand_dev());
        // std::uniform_int_distribposiution<int>  distr(0, size);

        // startPosition(distr(generator), 0);
        // endPosition(distr(generator), size-1);
        // maze.setStartPosition(startPosition);
        // maze.setCurrentPosition(startPosition);
        // maze.setEndPosition(endPosition);
        // Position startPosition(distr(generator), 0);
        // Position endPosition(distr(generator), size-1);
        // maze.setStartPosition(startPosition);
        // maze.setCurrentPosition(startPosition);
        // maze.setEndPosition(endPosition);

        // //Choose the initial cell, mark it as visited and push it to the stack
        // _stack.push(maze.getCurrentPosition());

        // //While the stack is not empty
        // while (!_stack.empty())
        // {
        //     // maze.setCurrentPosition(_stack.pop());
        //     for (int i = 0; i < size; i++)
        //     {
        //         for (int j = 0; j < size; j++)
        //         {

        //             if (maze.getCurrentPosition() == maze.getStartPosition())
        //             {
        //                 /* code */
        //             }

        //         }

        //     }

        // }

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
    std::queue<Position> _stack;
};