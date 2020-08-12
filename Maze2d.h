
#ifndef MAZEPROJECT_MAZE2D_H
#define MAZEPROJECT_MAZE2D_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//class Position represents a possible position to be in during the game
class Position
{
public:
//implement << operator
//implement = operator

Position():_x(NULL), _y(NULL){}
Position(int x, int y): _x(x), _y(y){}


//bool operator == (Position& position) {return ()} //??? 

private:
	int _x;
	int _y;
};


//class Searchable represents a problem that can be searched
class Searchable
{
	virtual Position& getStartPosition()=0;
	virtual Position& getGoalPosition()=0;
	virtual std::vector<string> getPossibleMoves()=0;
};

class Maze2dSearchable : public Searchable
{
public:
	Maze2dSearchable(Maze2d& maze): _maze(maze){}
	virtual Position& getStartPosition(){return _maze.getStartPosition();}
	virtual Position& getGoalPosition(){return _maze.getEndPosition();}

private:
	Maze2d _maze;

};

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

        // for (int i = 0; i < size; i++) 
        // { 
        //     for (int j = 0; j < size; j++)
        //     { 
        //         std::cout<< maze[i][j]<< " "; 
        //     } 
        // std::cout<< "\n"; 
        // } 
	}
	Position getStartPosition(){return this->start;}
	Position getEndPosition(){return this->end;}
	Position getCurrentPosition(){return this->current;} ///not sure if necessary, delete later if not!!!!
	
	//TODO MAYBE: implement == operator if we need it for caching
	
	
private:
	std::vector<std::vector<int> > maze;
	Position start, end, current;
};




#endif //MAZEPROJECT_MAZE2D_H
