//
// Created by Sapir Ezra on 24/08/2020.
//

#ifndef MAZEPROJECT_MYVIEW_H
#define MAZEPROJECT_MYVIEW_H
#include "View.h"

class MyView : public View
{
    virtual void display(Maze2d &maze); //todo: need to implement
	virtual void showMsg(std::string s); //todo: cout msg to the screen
};


#endif //MAZEPROJECT_MYVIEW_H
