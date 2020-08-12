
#ifndef MAZEPROJECT_MAZE2D_H
#define MAZEPROJECT_MAZE2D_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Position
{
public:
//implement << operator
//implement = operator

private:
	int x;
	int y;
};



class Maze2d
{
public:
	Position getStartPosition();
	//TODO MAYBE: implement == operator if we need it for caching
	std::vector<string> getPossibleMoves();
	Position getGoalPosition();
private:
	std::vector<std::vector<int>> maze;
	Position start, end, current;
};




#endif //MAZEPROJECT_MAZE2D_H
