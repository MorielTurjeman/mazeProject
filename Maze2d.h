
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
	Position() : _x(0), _y(0) {}
	Position(int x, int y) : _x(x), _y(y) {}

public:
	bool operator==(const Position &position)const { return (_x == position._x) && (_y == position._y); } 
	bool operator!=(const Position &position)const { return !this->operator==(position); }
	//implement << operator
	void operator<<(Position p)const {std::cout<<"("<<p.getXPosition()<<","<<p.getYPosition()<<")"<<std::endl;}
	int getXPosition() const { return _x; };
	int getYPosition() const { return _y; };

private:
	int _x;
	int _y;
};

/**************************************************************************************/

//represents a state in a search problem(the position and the distance from root)



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
				maze[i][j] = 0;
			}
		}
	}

public:
	std::vector<std::vector<int> > &getMaze() {return maze; }
	Position getStartPosition() { return this->start; }
	Position getEndPosition() { return this->end; }
	Position getCurrentPosition() { return this->current; } //not sure if necessary, delete later if not!!!!!
	void setStartPosition(Position p) { this->start = p; }
	void setEndPosition(Position p) { this->end = p; }
	void setCurrentPosition(Position p) { this->current = p; }

	//TODO MAYBE: implement == operator if we need it for caching

	virtual const std::vector<Position> getPossibleMoves(Position &p, int mazeSize)
	{
		std::vector<Position> possibleMoves;
		int x = p.getXPosition();
		int y = p.getYPosition();
<<<<<<< HEAD
		if ((x < mazeSize-1) && (maze.at(x + 1).at(y)!= 1))
=======
		if (((x < mazeSize-1) && (((maze.at(x + 1).at(y)==0) || (maze.at(x + 1).at(y)==2)))))
>>>>>>> eb30feee9a85a9cd5b1e7c8f81dfcb7c5e09f92c
		{
			Position p(x + 1, y);
			possibleMoves.push_back(p);
		}
<<<<<<< HEAD
		if ((x > 0) && (maze.at(x-1).at(y) != 1))
=======
		if (((x > 0) && (((maze.at(x-1).at(y)==0)) || (maze.at(x-1).at(y)==2))))
>>>>>>> eb30feee9a85a9cd5b1e7c8f81dfcb7c5e09f92c
		{
			Position p(x - 1, y);
			possibleMoves.push_back(p);
		}
<<<<<<< HEAD
		if ((y < mazeSize-1) && (maze.at(x).at(y+1) != 1))
=======
		if (((y < mazeSize-1) && (((maze.at(x).at(y+1)==0) || (maze.at(x).at(y+1)==2)))))
>>>>>>> eb30feee9a85a9cd5b1e7c8f81dfcb7c5e09f92c
		{
			Position p(x, y + 1);
			possibleMoves.push_back(p);
		}
<<<<<<< HEAD
		if ((y > 0) && (maze.at(x).at(y-1)!=1))
=======
		if (((y > 0) && (((maze.at(x).at(y-1)==0)) || (maze.at(x).at(y-1)==0))))
>>>>>>> eb30feee9a85a9cd5b1e7c8f81dfcb7c5e09f92c
		{
			Position p(x, y - 1);
			possibleMoves.push_back(p);
		}
		return possibleMoves;
	}

	void printMaze()
	{
		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze.size(); j++)
			{
				std::cout << maze[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

private:
	std::vector<std::vector<int> > maze;
	Position start, end, current;
};

#endif //MAZEPROJECT_MAZE2D_H
