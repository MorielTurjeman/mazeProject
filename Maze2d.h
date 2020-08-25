#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Maze2d.h"
#include <random>
using namespace std;

//class Position represents a possible position to be in during the game
class Position
{
public:
	Position() : _x(0), _y(0) {}
	Position(int x, int y) : _x(x), _y(y) {}

public:
	bool operator==(const Position &position) const { return (_x == position._x) && (_y == position._y); }
	bool operator!=(const Position &position) const { return !this->operator==(position); }
	int getXPosition() const { return _x; };
	int getYPosition() const { return _y; };

private:
	int _x;
	int _y;
};

/**************************************************************************************/


class Maze2d
{
public:
	friend ostream &operator<<(ostream &os, const Maze2d &m)
	{
			m.printMaze(os);
			return os;
	}
	Maze2d(int size, bool fillWalls = false)
	{

		int defaultValue = fillWalls ? 1 : 0;
		maze.resize(size);
		for (int i = 0; i < size; i++)
		{
			maze[i].resize(size);
			for (int j = 0; j < size; j++)
			{
				maze[i][j] = fillWalls;
			}
		}
	}

	//this constructor uses a vector created by the 'getData' method in this class
	Maze2d(std::vector<int> mazeData)
	{
		
		int size = mazeData[4];

		maze.resize(size);
		for (int i = 0; i < size; i++)
		{
			maze[i].resize(size);
		
		}

		Position startPosition(mazeData[0], mazeData[1]);
		this->setStartPosition(startPosition);
		Position endPosition(mazeData[2], mazeData[3]);
		this->setEndPosition(endPosition);
		
		// Maze2d _maze(size);
		int currVectorIndex = 5;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				maze[i][j] = mazeData[currVectorIndex];
				currVectorIndex++;
			}
		}
	}

	std::vector<std::vector<int>> &getMaze() { return maze; }
	Position getStartPosition() { return this->start; }
	Position getEndPosition() { return this->end; }
	Position getCurrentPosition() { return this->current; } //not sure if necessary, delete later if not!!!!!
	void setStartPosition(Position p)
	{
		this->start = p;
		maze[p.getYPosition()][p.getXPosition()] = 0;
	}
	void setEndPosition(Position p)
	{
		this->end = p;
		maze[p.getYPosition()][p.getXPosition()] = 0;
	}
	void setCurrentPosition(Position p) { this->current = p; }
	void setMazeName(std::string mazeName) { _mazeName = mazeName; }
	std::string getMazeName() { return _mazeName; }

	void setCurrentPosition(int x, int y)
	{
		Position p(x, y);
		this->current = p;
	}

	//TODO MAYBE: implement == operator if we need it for caching

	std::vector<int> getData()
	{
		std::vector<int> mazeData;
		mazeData.push_back(getStartPosition().getXPosition());
		mazeData.push_back(getStartPosition().getYPosition());
		mazeData.push_back(getEndPosition().getXPosition());
		mazeData.push_back(getEndPosition().getYPosition());
		mazeData.push_back(maze.size());
		int size = maze.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				mazeData.push_back(maze[i][j]);
			}
		}
		return mazeData;
	}

	virtual const std::vector<Position> getNeighbours(Position &p)
	{
		std::vector<Position> pMoves;
		int row = p.getYPosition();
		int col = p.getXPosition();

		if (row - 2 >= 1)
		{
			Position up(col, row - 2);
			pMoves.push_back(up);
		}

		if (row + 2 <= maze.size() - 2)
		{

			Position down(col, row + 2);
			pMoves.push_back(down);
		}

		if (col - 2 >= 1)
		{
			Position left(col - 2, row);
			pMoves.push_back(left);
		}

		if (col + 2 <= maze.size() - 2)
		{
			Position right(col + 2, row);
			pMoves.push_back(right);
		}

		return pMoves;
	}

	virtual const std::vector<Position> getPossibleMoves(Position &p)
	{
		std::vector<Position> pMoves;
		int row = p.getYPosition();
		int col = p.getXPosition();

		if (row - 1 >= 0 && maze[row - 1][col] != 1)
		{
			Position up(col, row - 1);
			pMoves.push_back(up);
		}

		if (row + 1 <= maze.size() - 1 && maze[row + 1][col] != 1)
		{

			Position down(col, row + 1);
			pMoves.push_back(down);
		}

		if (col - 1 >= 0 && maze[row][col - 1] != 1)
		{
			Position left(col - 1, row);
			pMoves.push_back(left);
		}

		if (col + 1 <= maze.size() - 1 && maze[row][col + 1] != 1)
		{
			Position right(col + 1, row);
			pMoves.push_back(right);
		}

		// auto neighbors = getNeighbours(p);
		// vector<Position> pMoves;
		// for (auto p : neighbors)
		// 	if (maze[p.getYPosition()][p.getXPosition()] == 0)
		// 		pMoves.push_back(p);
		return pMoves;
	}

	void printMaze(std::ostream& out = std::cout) const
	{
		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze.size(); j++)
			{
				if (maze[i][j] == 1)
					out << "\u2593";
				else if (i == start.getYPosition() && j == start.getXPosition())
				{
					out << "*";
				}
				else
				{
					out << " ";
				}
			}
			out << "\n";
		}
		out << "Start Position Row: " << start.getYPosition() << ", Column: " << start.getXPosition() << std::endl;
		out << "End Position Row: " << end.getYPosition() << ", Column: " << end.getXPosition() << std::endl;
	}

	void removeWall(Position &first, Position &second)
	{
		maze[first.getYPosition()][first.getXPosition()] = 0;
		maze[second.getYPosition()][second.getXPosition()] = 0;
		if (first.getXPosition() == second.getXPosition())
			maze[std::min(first.getYPosition(), second.getYPosition()) + 1][first.getXPosition()] = 0;
		else
			maze[first.getYPosition()][std::min(first.getXPosition(), second.getXPosition()) + 1] = 0;

		// int col = p.getXPosition();
		// int row = p.getYPosition();

		// [row][col]: [0][0] [0][1] [0][2] [0][3] [0][4]
		// maze[row][col] = 0;
		return;
	}

	void setWall(Position &p)
	{
		int col = p.getXPosition();
		int row = p.getYPosition();

		// [row][col]: [0][0] [0][1] [0][2] [0][3] [0][4]
		maze[row][col] = 1;
		return;
	}

	Position randomWallPosition()
	{
		std::vector<Position> wallPosition;
		for (int i = 1; i < maze.size() - 1; i += 2)
		{
			wallPosition.push_back({0, i});
			wallPosition.push_back({i, 0});
			wallPosition.push_back({i, (int)maze.size() - 1});
			wallPosition.push_back({(int)maze.size() - 1, i});
		}

		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<int> distribution(0, wallPosition.size() - 1);
		int idx = distribution(generator);

		return wallPosition[idx];
	}

private:
	std::vector<std::vector<int>> maze;
	Position start, end, current;
	std::string _mazeName;
};
