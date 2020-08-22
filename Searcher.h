#pragma once

#include "Searcable.h"
#include "Maze2d.h"
#include <queue>
#include "Solution.h"
#include <vector>
//class Searcher represents algorithms that solve problems by searching
template <class T>
class Searcher
{
    virtual void search(Searchable<T> &searchable) = 0; //check what the function needs to return
    //how do we keep the path to the goal
};

//commonly, search algorithms have a priority queue for evaluating the next best option to go to
template <class T>
class CommonSearcher : public Searcher<T>
{
    virtual bool priorityFunction(const State<T> &a, const State<T> &b) = 0;
    virtual Solution<T> search(Searchable<T> &searchable)
    {
        auto comperatorLambda = [&](State<T> a, State<T> b) -> bool { return priorityFunction(a, b); };
        std::priority_queue<State<T>, std::vector<State<T>>, decltype(comperatorLambda)> pq(comperatorLambda);
        pq.push(searchable.getStartState());
        std::vector<State<T>> visited;
        while (!pq.empty())
        {
            auto state = pq.top();
            pq.pop();

            if (searchable.getGoalState() == state)
            {
                auto sol = Solution(std::make_shared<State<T>>(state));
                return sol;
                //return Class solution (maybe new file) that will return vector with all the path to the solution.
            }

            else
            {
                for (auto getPS : searchable.getPossibleStates(state))
                {
                    if (std::find(visited.begin(), visited.end(), getPS) == visited.end()) //if the state was not found
                    {
                        visited.push_back(getPS);
                        pq.push(getPS);
                    }
                }
            }
        }
    }
};
template <class T>
class BFS : public CommonSearcher<T>
{
    virtual bool priorityFunction(const State<T> &a, const State<T> &b) // f()
    {
        return (a.cost > b.cost); // g(a) > g(b)
    }
};

template <class T>
class Hueristics // interface- define how hueristics look like
{
    virtual double operator()(const State<T> &state) const = 0;
};

template <class T>
class AStar : public CommonSearcher<T>
{
private:
    Hueristics<T> &_h;
    AStar(Hueristics<T> &h) : _h(h) {}

    virtual bool priorityFunction(const State<T> &a, const State<T> &b)
    {
        return (a.cost + h(a) > b.cost + h(b));
    }
};
