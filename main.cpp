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



    CLI cli(std::cin, std::cout);
    auto mm = std::make_shared<MyModel>();
    // auto cli = std::make_shared<CLI>(std::cin, std::cout);// CLI cli(std::cin, std::cout);
    auto mv = std::make_shared<MyView>(cli);// MyView mv(cli);
    auto mc = std::make_shared<MyController>(mm, mv);// MyController mc(mm, mv);
    
    mc->start();
    
    return 0;
}