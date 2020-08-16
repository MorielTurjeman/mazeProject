#include "Maze2d.h"
#include "Searcable.h"

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