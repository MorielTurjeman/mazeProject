# mazeProject

In this project we built a two-dimentional maze game and used algorithms to solve it.

We made sure to seperate the problem from the solution.
This is why we have a class "Searchable" that represents a problem that can solved using search,
and a class "Searcher" that represents an algorithm that solves a "Searchable" problem.

It was important to us to keep the interface and the implementation of the solution algorithms seperated;
we created a class called "CommonSearcher" because many search algorithms have a priority queue for evaluating the next best option to go to. Any derived class that will inherit from this class will have to implement a proiority queue.
However, we kept the option to add solution algorithms that don't have a priority queue: if we need to add them in the future they will be derived from "Searcher" instead of "CommonSearcher".