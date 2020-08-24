
#ifndef MAZEPROJECT_MAZE2D_H
#define MAZEPROJECT_MAZE2D_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Maze2d.h"
#include<random>
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
	//implement << operator
	// void operator<<(Position p) const { std::cout << "(" << p.getXPosition() << "," << p.getYPosition() << ")" << std::endl; } should be friend
	int getXPosition() const { return _x; };
	int getYPosition() const { return _y; };
	void setMazeName(std::string mazeName) {_mazeName = mazeName;}
	std::string getMazeName(){return _mazeName;}

private:
	int _x;
	int _y;
	std::string _mazeName;
};

/**************************************************************************************/

class Maze2d
{
public:
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
		Position startPosition(mazeData[0], mazeData[1]);
		this->setStartPosition(startPosition);
		Position endPosition(mazeData[2], mazeData[3]);
		this->setEndPosition(endPosition);
		int size = mazeData[4];
		Maze2d _maze(size);
		int currVectorIndex = 5;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				_maze.getMaze()[i][j] = mazeData[currVectorIndex];
				currVectorIndex++;
			}
		}
	}

	std::vector<std::vector<int>> &getMaze() { return maze; }
	Position getStartPosition() { return this->start; }
	Position getEndPosition() { return this->end; }
	Position getCurrentPosition() { return this->current; } //not sure if necessary, delete later if not!!!!!
	void setStartPosition(Position p) { this->start = p; maze[p.getYPosition()][p.getXPosition()] = 0; }
	void setEndPosition(Position p) { this->end = p;  maze[p.getYPosition()][p.getXPosition()] = 0;}
	void setCurrentPosition(Position p) { this->current = p; }
	void setCurrentPosition(int x, int y)
	{
		Position p(x, y);
		this->current = p;
	}

	//TODO MAYBE: implement == operator if we need it for caching

	std::vector<int> getData(Maze2d maze)
	{
		std::vector<int> mazeData;
		mazeData.push_back(maze.getStartPosition().getXPosition());
		mazeData.push_back(maze.getStartPosition().getYPosition());
		mazeData.push_back(maze.getEndPosition().getXPosition());
		mazeData.push_back(maze.getEndPosition().getYPosition());
		mazeData.push_back(maze.getMaze().size());
		int size = maze.getMaze().size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				mazeData.push_back(maze.getMaze()[i][j]);
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

	void printMaze()
	{
		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze.size(); j++)
			{
				if (maze[i][j] == 1)
					std::cout << "\u2593";

				else
				{
					std::cout << " ";
				}
			}
			std::cout << "\n";
		}
	}

	void alternativePrintMaze()
	{
		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze.size(); j++)
			{
				if (maze[i][j] == maze[this->getStartPosition().getXPosition()][this->getStartPosition().getYPosition()])
				{
					std::cout << "S ";
					continue;
				}
				if (maze[i][j] == maze[this->getEndPosition().getXPosition()][this->getEndPosition().getYPosition()])
				{
					std::cout << " E";
					continue;
				}

				if (maze[i][j] == 1)
				{
					std::cout << "{}";
				}

				if (maze[i][j] == 0)
				{
					std::cout << "  ";
				}
				// std::cout << "|";

				// std::cout << maze[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	void removeWall(Position &first, Position &second)
	{
		maze[first.getYPosition()][first.getXPosition()] = 5;
		maze[second.getYPosition()][second.getXPosition()] = 5;
		if (first.getXPosition() == second.getXPosition())
			maze[std::min(first.getYPosition(), second.getYPosition()) + 1][first.getXPosition()] = 5;
		else
			maze[first.getYPosition()][std::min(first.getXPosition(), second.getXPosition()) + 1] = 5;

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
		for (int i = 1; i < maze.size() - 1; i+=2)
		{
			wallPosition.push_back({0, i});
			wallPosition.push_back({i, 0});
			wallPosition.push_back({i, (int)maze.size()-1});
			wallPosition.push_back({(int)maze.size()-1, i});

		}

		std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, wallPosition.size()-1);
		int idx=distribution(generator);

		return wallPosition[idx];
	}

private:
	std::vector<std::vector<int>> maze;
	Position start, end, current;
	// int _width; if decided to be rectangle then should be width and height
	//int height;
};

#endif //MAZEPROJECT_MAZE2D_H
