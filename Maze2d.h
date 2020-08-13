
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
	// bool operator==(Position &position) { return false; } //implement here
	bool operator!=(Position position) { return !(_x == position._x) && (_y == position._y); }
	//implement << operator
	int getXPosition() { return _x; };
	int getYPosition() { return _y; };

private:
	int _x;
	int _y;
};

/**************************************************************************************/

//represents a state in a search problem(the position and the distance from root)
class State
{

public:
	Position p;
	int cost;
	bool operator==(const State &other) const
	{
		if (this->p.getXPosition() == other.getXposition() && this->p.getYPosition() == other->p.getYPosition())
			return true;
		return false;
	}
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
				maze[i][j] = 0;
			}
		}
	}

public:
	std::vector<std::vector<int>> getMaze() { return maze; }
	Position getStartPosition() { return this->start; }
	Position getEndPosition() { return this->end; }
	Position getCurrentPosition() { return this->current; } //not sure if necessary, delete later if not!!!!!
	void setStartPosition(Position p) { this->start = p; }
	void setEndPosition(Position p) { this->end = p; }
	void setCurrentPosition(Position p) { this->current = p; }

	//TODO MAYBE: implement == operator if we need it for caching

	virtual const std::vector<Position> getPossibleMoves(Position &p)
	{
		std::vector<Position> possibleMoves;
		int x = p.getXPosition();
		int y = p.getYPosition();
		if (maze[x + 1][y])
		{
			Position p(x + 1, y);
			possibleMoves.push_back(p);
		}
		if (maze[x - 1][y])
		{
			Position p(x - 1, y);
			possibleMoves.push_back(p);
		}
		if (maze[x][y + 1])
		{
			Position p(x, y + 1);
			possibleMoves.push_back(p);
		}
		if (maze[x][y - 1])
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
	std::vector<std::vector<int>> maze;
	Position start, end, current;
};

#endif //MAZEPROJECT_MAZE2D_H
