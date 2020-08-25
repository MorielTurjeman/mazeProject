#include <iostream>
#include <string>
#include <vector>
#include "Controller.h"
#include <random>
#include"Demo.h"
#include "CLI.h"
#include "MyView.h"
#include "MyController.h"
#include "MyModel.h"

#include "SimpleMaze2dGenerator.h"

int main(int argc, char const *argv[])
{
    // Demo demo;
    // demo.run();

    // std::cout << "hello world" << std::endl;

    // time_t start_time = time(NULL);
    // std::cout << ctime(&start_time) << std::endl;
    // SimpleMaze2dGenerator G;
    // auto maze =G.generate(11);
    // maze.printMaze();
    // MyMaze2dGenerator g;

    // auto maze = g.generate(31);
    // maze.printMaze();

    // Maze2dSearchable s(maze);
    //   // AerialDistance adp(s.getGoalState());
    // // AStar <Position> astar(adp);
    // // Solution<Position> sol= astar.search(s);
    // BFS <Position> b;
    // auto sol= b.search(s);
    
    // for( auto p: sol.getPath())
    // {
    //     std::cout<<p->data.getYPosition()<<" , "<<p->data.getXPosition()<<endl;
    // }
    




    // std::cout << ctime(&start_time) << std::endl;

    // time_t end_time = time(NULL);
    // std::cout << ctime(&end_time) << std::endl;

    CLI cli(std::cin, std::cout);
    auto mm = std::make_shared<MyModel>();
    // auto cli = std::make_shared<CLI>(std::cin, std::cout);// CLI cli(std::cin, std::cout);
    auto mv = std::make_shared<MyView>(cli);// MyView mv(cli);
    auto mc = std::make_shared<MyController>(mm, mv);// MyController mc(mm, mv);
    
    mc->start();
    
    return 0;
}