#pragma once

#include "Maze2d.h"

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