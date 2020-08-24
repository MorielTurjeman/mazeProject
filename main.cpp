#include <iostream>
#include <string>
#include <vector>
#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include <random>


int main(int argc, char const *argv[])
{
    std::cout << "hello world" << std::endl;

    time_t start_time = time(NULL); 
    std::cout << ctime(&start_time) << std::endl;
    SimpleMaze2dGenerator G;
    auto maze =G.generate(11);
    maze.printMaze();
    // MyMaze2dGenerator g;


    // auto maze = g.generate(41);
    // maze.printMaze();
    // checkPossibleMoves(30);
    // std::cout << maze.getMaze().size() << std::endl;
    std::cout << ctime(&start_time) << std::endl;    

	time_t end_time = time(NULL);
    std::cout << ctime(&end_time) << std::endl;



    return 0;
}