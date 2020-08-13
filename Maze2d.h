
#ifndef MAZEPROJECT_MAZE2D_H
#define MAZEPROJECT_MAZE2D_H

#include <iostream>
#include <string>
#include <vector>
#include "Maze2d.h"


using namespace std;

//class Position represents a possible position to be in during the game
class Position
{
public:
	Position():_x(0), _y(0){}
	Position(int x, int y): _x(x), _y(y){}

public:
	bool operator==(Position& position) {return false;} //implement here
	//implement << operator
	//implement = operator
	int getXPosition(){return _x;};
	int getYPosition(){return _y;};
private:
	int _x;
	int _y;
};

//represent state in a search problem(the position and distance from root)
class State{

public:
	Position p;
	int cost;


};

//class Searchable represents a problem that can be searched


/**************************************************************************************/ 

class Maze2d
{
public:
	Maze2d(int size)
	{
        maze.resize(size);
        for (int i = 0; i < size; i++) 
        { 
            maze[i].resize(size);
            for (int j = 0; j < size; j++)
            { 
                maze[i][j]=0;
            } 
        } 

        for (int i = 0; i < size; i++) 
        { 
            for (int j = 0; j < size; j++)
            { 
                std::cout<< maze[i][j]<< " "; 
            } 
        std::cout<< "\n"; 
        } 
	}
	Maze2d(){Maze2d(10);} //if no size was given, the default will be 10x10 board
	std::vector<std::vector<int> > getMaze(){return maze;}

public:
	Position getStartPosition(){return this->start;}
	Position getEndPosition(){return this->end;}
	Position getCurrentPosition(){return this->current;} //not sure if necessary, delete later if not!!!!!

	
	//TODO MAYBE: implement == operator if we need it for caching
	
	virtual const std::vector<Position> getPossibleMoves(Position &p)
	{
		std::vector<Position> possibleMoves;
		int x=p.getXPosition();
		int y=p.getYPosition();
		if(maze[x+1][y])
		{
			possibleMoves.push_back({x+1, y});
		}
		if(maze[x-1][y])
		{
			possibleMoves.push_back({x-1, y});
		}
		if(maze[x][y+1])
		{
			possibleMoves.push_back({x, y+1});
		}
		if(maze[x][y-1])
		{
			possibleMoves.push_back({x, y-1});
		}
	}
private:
	std::vector<std::vector<int> > maze;
	Position start, end, current;
};




#endif //MAZEPROJECT_MAZE2D_H
