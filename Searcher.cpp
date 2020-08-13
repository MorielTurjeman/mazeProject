#include <queue>
#include "Maze2d.h"
#include "Searcher.h"
#include <algorithm>

void CommonSearcher::search(Searchable &Searchable)
{
    auto comperatorLambda = [&](State a, State b) -> bool { return priorityFunction(a, b); };
    std::priority_queue<State, std::vector<State>, decltype(comperatorLambda)> pq(comperatorLambda);
    pq.push(Searchable.getStartState());
    std::vector<State> visited;
    while (!pq.empty())
    {
        auto state = pq.top();
        pq.pop();

        if (Searchable.getGoalState() == state)
        {
            //return Class solution (maybe new file) that will return vector with all the path to the solution.
        }

        else
        {
            for (auto getPS : Searchable.getPossibleStates(state))
            {
                if (std::find(visited.begin(), visited.end(), getPS) == visited.end())//if the state was not found
                {
                    visited.push_back(getPS);
                    pq.push(getPS);

                }



            }
        }
    }

}
