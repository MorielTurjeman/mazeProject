
//
// Created by Sapir Ezra on 11/08/2020.
//

#include "Maze2d.h"
#include "Maze2dSearchable.h"


// std::string Maze2d::measureAlgorithmTime()
// {

// }

const std::vector<State<Position>> Maze2dSearchable::getPossibleStates(State<Position> &currState)
{
   std::vector<Position> position = _maze.getPossibleMoves(currState.data);

   std::vector<State<Position>> S;
   for (auto &p : position)
   {
      S.push_back({p, currState.cost + 1, std::make_shared<State<Position>>(currState)});
   }

   return S;
}