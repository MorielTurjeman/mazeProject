#include <iostream>
#include <string>
#include <vector>
#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"

int main(int argc, char const *argv[])
{
    std::cout << "hello world" << std::endl;

    time_t start_time = time(NULL); 
    std::cout << ctime(&start_time) << std::endl;

    Maze2d m(10);
    SimpleMaze2dGenerator smp;

    time_t end_time = time(NULL); 
    std::cout << ctime(&end_time) << std::endl;

    return 0;
}