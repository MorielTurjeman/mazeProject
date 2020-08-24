#include <iostream>
#include <string>
#include <vector>
#include "Maze2d.h"
#include "Maze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include "Controller.h"
#include <random>

class NameLater //take #include "Controller.h" //todo: move to main????
{
	void getCommand()
	{
		std::string  command = "";
		while(command.compare("exit") != 0)
		{
			Controller* controller = new Controller();
			std::cout << "Please enter command: " << std::endl;
			std::cin >> command;

			Command* cmd = controller->get(command);

			if (nullptr != cmd)
			{
				cmd->execute();
			}
			else
			{
				std::cout << "Unsupported command!" << std::endl;
			}	
		}
	}
};


int main(int argc, char const *argv[])
{
    std::cout << "hello world" << std::endl;

    time_t start_time = time(NULL); 
    std::cout << ctime(&start_time) << std::endl;
    SimpleMaze2dGenerator G;
    auto maze =G.generate(40);
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