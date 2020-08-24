#include <iostream>
#include <string>
#include <vector>
#include "Controller.h"
#include <random>
#include"Demo.h"
// class NameLater //take #include "Controller.h" //todo: move to main????
// {
//     void getCommand()
//     {
//         std::string command = "";
//         while (command.compare("exit") != 0)
//         {
//             Controller *controller = new Controller();
//             std::cout << "Please enter command: " << std::endl;
//             std::cin >> command;

//             Command *cmd = controller->get(command);

//             if (nullptr != cmd)
//             {
//                 cmd->execute();
//             }
//             else
//             {
//                 std::cout << "Unsupported command!" << std::endl;
//             }
//         }
//     }
// };

#include "SimpleMaze2dGenerator.h"

int main(int argc, char const *argv[])
{
    Demo demo;
    demo.run();

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

    return 0;
}