
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

//represent state in a search problem(the position and distance from root)
class State{

public:
	Position p;
	int cost;


};

//class Searchable represents a problem that can be searched
class Searchable
{
	virtual const Position& getStartPosition()=0;
	virtual const Position& getGoalPosition()=0;
	virtual const std::vector<State> getPossibleStates(State& currState)=0; // we need to return search state and not position. the vector holds serach states (the tree).
};

//create search states for maze problem
class Maze2dSearchable : public Searchable
{
public:
	Maze2dSearchable(Maze2d& maze): _maze(maze){}
	virtual const Position& getStartPosition(){return _maze.getStartPosition();}
	virtual const Position& getGoalPosition(){return _maze.getEndPosition();}


	virtual const std::vector<State> getPossibleStates(State& currState); 


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
	
	virtual const std::vector<string> getPossibleMoves(Position &p)
	{
		std::vector<string> possibleMoves;
		if(p.getXPosition+1 == 0)
		{
			possibleMoves.push_back("Right");
		}
		if(p.getXPosition-1 == 0)
		{
			possibleMoves.push_back("Left");
		}
		if(p.getYPosition+1 == 0)
		{
			possibleMoves("Down");
		}
		if(p.getYPosition-1 == 0)
		{
			possibleMoves("Up");
		}
	}
private:
	std::vector<std::vector<int> > maze;
	Position start, end, current;
};




#endif //MAZEPROJECT_MAZE2D_H
