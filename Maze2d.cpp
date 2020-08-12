//
// Created by Sapir Ezra on 11/08/2020.
//

#include "Maze2d.h"

// std::string Maze2d::measureAlgorithmTime()
// {
    
// }

 const std::vector<State> Maze2dSearchable::getPossibleStates(State& currState){
    //  std::vector<state> states= _maze.getPossibleMoves(currState.p);
    _maze.getPossibleMoves(currState.p);
 }