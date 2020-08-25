//
// Created by Sapir Ezra on 23/08/2020.
//

#pragma once
#include <unordered_map>
#include <string>
#include "Command.h"
#include "Maze2d.h"
#include "Model.h"
#include "View.h"

class Controller
{
public:
	virtual shared_ptr<Command> get(const std::string &command) = 0;

protected:
	

};
