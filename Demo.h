//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_DEMO_H
#define MAZEPROJECT_DEMO_H
#include "MyMaze2dGenerator.h"
#include "Searcher.h"
#include "Searcable.h"
#include "Maze2dSearchable.h"


class Demo
{
public:
	Demo(){}
	~Demo(){}
	void run(int size)
	{
		Maze2dGeneratorAbs* _mazeGen = new MyMaze2dGenerator;
		Maze2d myMaze = _mazeGen->generate(size);
		myMaze.printMaze();

		Maze2dSearchable s(myMaze);
		BFS<Position> bfs;
		auto sol = bfs.search(s);
		for(auto p : sol.getPath())
		{
			std::cout << p->data.getYPosition() << " ," << p->data.getYPosition() << std::endl;
		}
		

	}
};


#endif //MAZEPROJECT_DEMO_H
