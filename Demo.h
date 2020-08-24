#pragma once
#include "MyMaze2dGenerator.h"
#include "Searcher.h"
#include "Maze2dSearchable.h"
#include <memory>

class Demo
{
public:
	Demo() {}
	void run()
	{
		std::shared_ptr<Maze2dGenerator> mazeGen = std::make_shared<MyMaze2dGenerator>();

		Maze2d myMaze = mazeGen->generate(31);
		myMaze.printMaze();
		
		Maze2dSearchable s(myMaze);
		BFS<Position> bfs;
		auto solBfs = bfs.search(s);

		std::cout << "BFS total state developed: " << bfs.getCounter() << endl;

		AerialDistance ad(s.getGoalState());
		AStar<Position> Arialdis(ad);
		auto solAerial = Arialdis.search(s);
	
		std::cout << "AStar aerial distance total state developed: " << Arialdis.getCounter() << endl;

		ManhattanDistance amd(s.getGoalState());
		AStar<Position> manhattendis(amd);
		auto solManhattan = manhattendis.search(s);
		std::cout << "AStar Manhatten distance  total state developed: " << manhattendis.getCounter() << endl;

		std::cout<<endl<<"The Solution: "<<endl;
		for (auto p : solManhattan.getPath())
		{
			std::cout << "Row: " << p->data.getYPosition() << " , Column: " << p->data.getXPosition() << std::endl;
		}
	}
};
