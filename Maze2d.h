
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
	//bool operator == (Position& position) {return ()} //??? 
	//implement << operator
	//implement = operator
	int getXPosition(){return _x;};
	int getYPosition(){return _y;};
private:
	int _x;
	int _y;
};

/**************************************************************************************/ 


//class Searchable represents a problem that can be searched
class Searchable
{
	virtual Position& getStartPosition()=0;
	virtual Position& getGoalPosition()=0;
	virtual std::vector<string> getPossibleMoves()=0;
};

/**************************************************************************************/ 

class Maze2dSearchable : public Searchable
{
public:
	Maze2dSearchable(Maze2d& maze): _maze(maze){}

public:
	virtual const Position& getStartPosition(){return  _maze.getStartPosition();}
	virtual const Position& getGoalPosition(){return _maze.getEndPosition();}
	virtual const std::vector<Position> getPossibleMoves(Position &p)
	{
		std::vector<Position> possibleMoves;
		int x=p.getXPosition();
		int y=p.getYPosition();
		if(_maze.getMaze[x+1][y])
		{
			possibleMoves.push_back(x+1, y);
		}
		if(_maze.getMaze[x-1][y]==0)
		{
			possibleMoves.push_back(x-1, y);
		}
		if(_maze.getMaze[x][y+1]==0))
		{
			possibleMoves.push_back(x, y+1);
		}
		if(_maze.getMaze[x][y-1]==0))
		{
			possibleMoves.push_back(x, y-1);
		}
	}

private:
	Maze2d _maze;

};

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
	
private:
	std::vector<std::vector<int> > maze;
	Position start, end, current;
};




#endif //MAZEPROJECT_MAZE2D_H
