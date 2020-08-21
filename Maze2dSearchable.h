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
    State<Position> _state;

public:
    ManhattanDistance(State<Position> &state) : _state(state) {}
    virtual double operator()(const State<Position> &state) const
    {
        return std::abs(state.data.getXPosition() - state.data.getXPosition()) + (state.data.getYPosition() - state.data.getYPosition());
    }
};

class AerialDistance : public Hueristics<Position>
{
private:
    State<Position> _state;

public:
    AerialDistance(State<Position> &state) : _state(state) {}

    virtual double operator()(const State<Position> &state) const
    {
        return std::sqrt(std::pow((state.data.getXPosition() - state.data.getXPosition()), 2) + (std::pow((state.data.getYPosition() - state.data.getYPosition()), 2)));
    }
};