#include <iostream>
#include <string>
#include <vector>
#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include <random>

Maze2d generate(int size)
    {
        Maze2d maze(size);
        maze.getMaze()[0][0]=2;
        maze.printMaze();
        
        
        //we pick randomly the wall for the start, 0-top wall, 1-right wall, 2-bottom wall, 3-left wall
        //the end position will be at the opposite wall
        
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

        std::uniform_int_distribution<int>  randomMove(0, possibleMoves.size()-1);
        while (currentPosition != endPosition)
        {
            maze.getMaze()[currentPosition.getXPosition()][currentPosition.getYPosition()] = 2;
            int randomMoveIndex=randomMove(generator);
            currentPosition = possibleMoves[randomMoveIndex]; //pick a possible move randomly from the vector of possible moves
        }

        std::uniform_int_distribution<int>  randomWall(0, 1);
        for (int i = 0; i < (size-1); i++)
        {
            for (int j = 0; j < (size-1); j++)
            {
                if (maze.getMaze()[i][j]!= 2)
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
        maze.printMaze();
        return maze;
    }

int main(int argc, char const *argv[])
{
    std::cout << "hello world" << std::endl;

    time_t start_time = time(NULL); 
    std::cout << ctime(&start_time) << std::endl;

    generate(10);

	time_t end_time = time(NULL);
    std::cout << ctime(&end_time) << std::endl;

    return 0;
}