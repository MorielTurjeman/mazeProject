//
// Created by Sapir Ezra on 21/08/2020.
//

#ifndef MAZEPROJECT_CLI_H
#define MAZEPROJECT_CLI_H
#include<iostream>
#include<string>


class CLI
{
public:
	CLI(std::istream in, std::ostream out);
	void start()
    {
        // while (!_in.eof())
        // {
            
        // }
        std::string x;
        int i=0;

        while (_in >> x)
        {
            i++;
        }
         
    }

private:
	std::istream _in;
	std::ostream _out;
};


#endif //MAZEPROJECT_CLI_H
