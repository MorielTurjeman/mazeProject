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
        if (size % 2 == 0)
            size++; //DFS algorithm requries an odd size square
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1, size - 2);
        int row = distribution(generator); //y
        if (row % 2 == 0)
            row += 1;
        int col = distribution(generator); //x
        if (col % 2 == 0)
            col -= 1;

   


        Position start{col, row};
        std::stack<Position> stack;
        std::vector<Position> visited;
        Maze2d maze(size, true);

        visited.push_back(start);
        stack.push(start);
        maze.getMaze()[row][col] = 0; // bad line, fix later so we cant edit the data directly!!!!!!!!!!!!!!!!!!
        
        Position enter= maze.randomWallPosition();
        Position exit=maze.randomWallPosition();
        maze.setStartPosition(enter);
        maze.setEndPosition(exit);

        while (!stack.empty())
        {
            
            Position current = stack.top(); // p is the parent
            stack.pop();
            auto pMoves = maze.getNeighbours(current); // the parents possible moves
            
            for(int i=pMoves.size()-1; i>=0 ; i--)
            {   
                if(std::find(visited.begin(), visited.end(), pMoves[i])!=visited.end())
                    pMoves.erase(pMoves.begin()+i);
            }

           if(!pMoves.empty())
           {
               stack.push(current);
               int idx=distribution(generator)%pMoves.size();
               maze.removeWall(current, pMoves[idx]);
               visited.push_back(pMoves[idx]);
               stack.push(pMoves[idx]);
           }
            
        }

        return maze;
    }

private:
};