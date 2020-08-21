
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

	//this constructor uses a vector created by the 'getData' method in this class
	Maze2d(std::vector<int> mazeData)
	{
		Position startPosition(mazeData[0], mazeData[1]);
		this->setStartPosition(startPosition);
		Position endPosition(mazeData[2], mazeData[3]);
		this->setEndPosition(endPosition);
		int size = mazeData[4]
		Maze2d _maze(size);
		int count=5;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				_maze[i][j] = mazeData[count];
				count++;
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
	void setCurrentPosition(int x, int y){Position p(x,y); this->current=p;}

	//TODO MAYBE: implement == operator if we need it for caching

	std::vector<int> getData(Maze2d maze)
	{
		std::vector<int> mazeData;
		mazeData.push_back(maze.getStartPosition().getXPosition());
		mazeData.push_back(maze.getStartPosition().getYPosition());
		mazeData.push_back(maze.getEndPosition().getYPosition());
		mazeData.push_back(maze.getEndPosition().getYPosition());
		mazeData.push_back(maze.getMaze().size());
		int size = maze.getMaze().size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				mazeData.push_back(maze[i][j]);
			}
		}
		return mazeData;
	}

	virtual const std::vector<Position> getPossibleMoves(Position &p, int mazeSize)
	{
		std::vector<Position> possibleMoves;
		int x = p.getXPosition();
		int y = p.getYPosition();
		if (((x < mazeSize-1) && (((maze.at(x + 1).at(y)==0) || (maze.at(x + 1).at(y)==2)))))
		{
			Position p(x + 1, y);
			possibleMoves.push_back(p);
		}
		if (((x > 0) && (((maze.at(x-1).at(y)==0)) || (maze.at(x-1).at(y)==2))))
		{
			Position p(x - 1, y);
			possibleMoves.push_back(p);
		}
		if (((y < mazeSize-1) && (((maze.at(x).at(y+1)==0) || (maze.at(x).at(y+1)==2)))))
		{
			Position p(x, y + 1);
			possibleMoves.push_back(p);
		}
		if (((y > 0) && (((maze.at(x).at(y-1)==0)) || (maze.at(x).at(y-1)==0))))
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

		void alternativePrintMaze()
	{
		for (int i = 0; i < maze.size(); i++)
		{
			for (int j = 0; j < maze.size(); j++)
			{
				if (maze[i][j]==maze[this->getStartPosition().getXPosition()][this->getStartPosition().getYPosition()])
				{
					std::cout<<"S ";
					continue;
				}
				if (maze[i][j]==maze[this->getEndPosition().getXPosition()][this->getEndPosition().getYPosition()])
				{
					std::cout<<" E";
					continue;
				}
				
				if(maze[i][j]==1)
				{
					std::cout<<"{}";
				}
					
				if(maze[i][j]==0)
				{
					std::cout<<"  ";
				}
				// std::cout << "|";
				
				// std::cout << maze[i][j] << " ";
				
			}
			std::cout << "\n";
		}
		
	}

private:
	std::vector<std::vector<int> > maze;
	Position start, end, current;
};

#endif //MAZEPROJECT_MAZE2D_H
