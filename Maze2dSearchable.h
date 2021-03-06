#pragma once

#include "Maze2d.h"
#include "Searcable.h"
#include "Searcher.h"
#include <cmath>
//create search states for maze problem
class Maze2dSearchable : public Searchable<Position>
{
public:
    Maze2dSearchable(Maze2d &maze) : _maze(maze) {}
    virtual const State<Position> getStartState()
    {
        return {_maze.getStartPosition(), 0};
    }
    virtual const State<Position> getGoalState()
    {
        return {_maze.getEndPosition(), 0};
    }

    virtual const std::vector<State<Position>> getPossibleStates(State<Position> &currState);

private:
    Maze2d _maze;
};

class ManhattanDistance : public Hueristics<Position>
{
private:
    const State<Position> _state;

public:
    ManhattanDistance(const State<Position> &state) : _state(state) {}
    virtual double operator()(const State<Position> &state) const
    {
        double h = std::abs(_state.data.getXPosition() - state.data.getXPosition()) + (_state.data.getYPosition() - state.data.getYPosition());
        // std::cout << "md " << h << std::endl;
        return h;
    }
};

class AerialDistance : public Hueristics<Position>
{
private:
    const State<Position> _state;

public:
    AerialDistance(const State<Position> &state) : _state(state) {}

    virtual double operator()(const State<Position> &state) const
    {
        double h = std::sqrt(std::pow((_state.data.getXPosition() - state.data.getXPosition()), 2) + (std::pow((_state.data.getYPosition() - state.data.getYPosition()), 2)));
        // std::cout << "ad " << h << std::endl;
        return h;
    }
};