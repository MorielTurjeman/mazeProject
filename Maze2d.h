
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
private:
	int x;
	int y;
};



class Maze2d
{
public:
	
private:
	std::vector<std::vector<int>> maze;
	Position start, end, current;
};




#endif //MAZEPROJECT_MAZE2D_H
