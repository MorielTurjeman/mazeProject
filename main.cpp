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
        
        // maze.printMaze();
        
        
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
        std::cout << "Start position is: " << startPosition.getXPosition() << ", " << startPosition.getYPosition() <<std::endl;

        Position currentPosition = maze.getCurrentPosition();
        Position endPosition = maze.getEndPosition();
        std::cout << "End position is: " << endPosition.getXPosition() << ", " << endPosition.getYPosition() <<std::endl;

        std::vector<Position> possibleMoves = maze.getPossibleMoves(startPosition, maze.getMaze().size());

        
        int count=0;
        while (currentPosition != endPosition)
        {
            std::cout<< "Loop count: " << count << std::endl;
            count++;
            if (possibleMoves.size() == 0)
            {
                std::cout << "error" <<std::endl;
            }
            std::uniform_int_distribution<int>  randomMove(0, possibleMoves.size()-1);
            maze.printMaze();
            maze.getMaze()[currentPosition.getXPosition()][currentPosition.getYPosition()] = 2;
            int randomMoveIndex=randomMove(generator);
            std::cout<<"Current: "<<currentPosition.getXPosition()<<","<<currentPosition.getYPosition()<<std::endl;
            std::cout << "Next move is: (" << possibleMoves.at(randomMoveIndex).getXPosition()<<","<<possibleMoves.at(randomMoveIndex).getYPosition()<<")"<<std::endl;
            currentPosition = possibleMoves.at(randomMoveIndex); //pick a possible move randomly from the vector of possible moves
            std::cout<<"Possible moves: "<<std::endl;
            
            for (int i = 0; i < possibleMoves.size(); i++)
            {
                std::cout << "(" <<possibleMoves.at(i).getXPosition()<<","<<possibleMoves.at(i).getYPosition()<<")"<<std::endl;
            }
            
                
            possibleMoves = maze.getPossibleMoves(currentPosition, maze.getMaze().size());
            std::cout <<"entered" <<std::endl;
        }

        maze.getMaze().at(startPosition.getXPosition()).at(startPosition.getYPosition())=4;
        maze.getMaze().at(endPosition.getXPosition()).at(endPosition.getYPosition())=3;

        std::uniform_int_distribution<int>  randomOneOrZero(0, 1);
        for (int i = 0; i < (maze.getMaze().size()); i++)
        {
            for (int j = 0; j < (maze.getMaze()[i].size()); j++)
            {
                if (maze.getMaze()[i][j]!= 2)
                {
                    int randomWallOrPassage = randomOneOrZero(generator);
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
                    maze.getMaze()[i][j] = 5; //mark the path to the goal as a passage
                }
            }
        }
        maze.getMaze().at(startPosition.getXPosition()).at(startPosition.getYPosition())=4;
        maze.getMaze().at(endPosition.getXPosition()).at(endPosition.getYPosition())=3;
        maze.printMaze();
        return maze;
    }

Maze2d generate2(int size)
{
    Maze2d maze(size);
    // std::cout << "Initial maze:" <<std::endl;
    // maze.printMaze();

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  randomIndexDistr(0, size-1);
    int randIndex= randomIndexDistr(generator);

    Position startPosition(randIndex, 0);
    Position endPosition(randIndex, size-1);
    maze.setStartPosition(startPosition);
    maze.setCurrentPosition(startPosition);
    maze.setEndPosition(endPosition);

    

    for (int i = 0; i < size; i++)
    {
        maze.getMaze()[randIndex][i]=2;
        
    }
    

    std::uniform_int_distribution<int>  randomOneOrZero(0, 1);
    for (int i = 0; i < (maze.getMaze().size()); i++)
    {
        for (int j = 0; j < (maze.getMaze()[i].size()); j++)
        {
            if (maze.getMaze()[i][j]!= 2)
            {
                int randomWallOrPassage = randomOneOrZero(generator);
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
    
    maze.getMaze()[startPosition.getXPosition()][startPosition.getYPosition()]=4;
    maze.getMaze()[endPosition.getXPosition()][endPosition.getYPosition()]=3;
    maze.printMaze();

    return maze;

}

Maze2d checkPossibleMoves(int size)
{
    Maze2d maze(size);
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  randomIndexDistr(0, size-1);
    int randIndex= randomIndexDistr(generator);

    Position startPosition(randIndex, 0);
    Position currentPosition(randIndex, 0);
    Position endPosition(randIndex, size-1);
    maze.setStartPosition(startPosition);
    maze.setCurrentPosition(startPosition);
    maze.setEndPosition(endPosition);

    maze.getMaze()[startPosition.getXPosition()][startPosition.getYPosition()]=4;
    maze.getMaze()[endPosition.getXPosition()][endPosition.getYPosition()]=3;

    std::vector<Position> possibleMoves = maze.getPossibleMoves(startPosition, maze.getMaze().size());
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout <<"Loop count: "<< count <<std::endl;
            count++;
            Position currPos(i,j);
            maze.setCurrentPosition(currPos);
            std::cout<<"Possible moves for (" <<i<<","<<j<<"): "<<std::endl;
            possibleMoves = maze.getPossibleMoves(currPos, maze.getMaze().size());
            for (int k = 0; k < possibleMoves.size(); k++)
            {
                std::cout << "(" <<possibleMoves.at(k).getXPosition() << "," <<possibleMoves.at(k).getYPosition()<<")"<<std::endl;
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

    generate2(10);

	time_t end_time = time(NULL);
    std::cout << ctime(&end_time) << std::endl;

    return 0;
}