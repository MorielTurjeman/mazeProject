//
// Created by Sapir Ezra on 21/08/2020.
//

#include "CLI.h"
#include "Controller.h"
vector<std::string> CLI::breakToWords(std::string line)
{
    std::stringstream ss(line);
    std::vector<std::string> words;
    do
    {
        std::string word;
        ss >> word;
        words.push_back(word);
    } while (ss);

    return words;
}
void CLI::start(std::shared_ptr<Controller> controller)
{
    std::string x;
    int i = 0;

    while (true)
    {
        // 1. the cli reads a line from the user
        // 2. it passes it to the controller
        // 3. the controller determines which command to run
        // 4. the controller returns the command
        // 5. the cli will pass the arguments to the command
        // 6. the cli will execute the command

        i++;
        std::string line;
        std::getline(_in, line);
        auto words = breakToWords(line);
        int commandLen = 0;
        auto command = controller->get(words[0] + " " + words[1]);
        if (command != nullptr)
        {
            commandLen = 2;
        }
        else
        {
            command = controller->get(words[0]);
            commandLen = 1;
        }

        if (command != nullptr)
        {
            command->setArgs(words.begin() + commandLen, words.end());
            command->execute(_out);
        }
    }
}

std::istream &CLI::getIn() { return _in; }
std::ostream &CLI::getout() { return _out; }
void CLI::setController(std::shared_ptr<Controller> controller)
{
    controller = controller;
}