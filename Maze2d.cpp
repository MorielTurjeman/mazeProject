//
// Created by Sapir Ezra on 11/08/2020.
//

#include "Maze2d.h"
#include "Searcable.h"

// std::string Maze2d::measureAlgorithmTime()
// {

// }

const std::vector<State> Maze2dSearchable::getPossibleStates(State &currState)
{
   std::vector<Position> position = _maze.getPossibleMoves(currState.p);

   std::vector<State> S;
   for (auto &p : position)
   {

      S.push_back({p, currState.cost + 1});
   }

   return S;

  
}