#include "Searcher.h"
#include <iostream>

#pragma once
template <class T>
class Solution
{
public:
    Solution(std::shared_ptr<State<T>> state) { buildSolution(); };
    //maybe implement getter to path if needed later
private:
    std::vector<std::shared_ptr<State<T>>> path; 
    void buildSolution(std::shared_ptr<State<T>> state)
    {
        if (state == nullptr)
            return;
        buildSolution(state->parent);
        path.push_back(state);
    }
};