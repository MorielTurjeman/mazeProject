#pragma once

#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include <random>
#include <stack>
class MyMaze2dGenerator : public Maze2dGeneratorAbs
{
public:
    ~MyMaze2dGenerator() {}
    virtual Maze2d generate(int size)
    {
        //https://hurna.io/academy/algorithms/maze_generator/dfs.html
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, size-1);
        int row = distribution(generator);//y
        int col= distribution(generator);//x
        //r[row][col]=>is actually (y,x) 
    
        Position start{col,row};
        std::stack<Position> stack;
        std::vector<Position> visited;
        stack.push(start);
        Maze2d maze(size);

        while(!stack.empty()){
            Position p = stack.top(); // p is the parent
            stack.pop();
            auto pMoves= maze.getPossibleMoves(p, size);// the parents possible moves

            if(!pMoves.empty())
            {
             
             auto idx= distribution(generator)% pMoves.size();
            
                for(int i=0; i<pMoves.size(); i++)
                {
                    

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
        

        /*
        Given a current cell as a parameter,
        Mark the current cell as visited
        While the current cell has any unvisited neighbour cells
            Choose one of the unvisited neighbours
            Remove the wall between the current cell and the chosen cell
            Invoke the routine recursively for a chosen cell

        */
    }
};