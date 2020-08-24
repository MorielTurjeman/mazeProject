#pragma once

#include <iostream>
#include <algorithm>
#include "Searcable.h"

template <class T>
class Solution
{
public:
    Solution(std::shared_ptr<State<T>> state) { buildSolution(state); };
    auto getPath() { return this->path; }
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
