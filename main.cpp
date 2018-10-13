/**
 * To-Do list command line app
 */

#include <iostream>
#include <stdint.h>
#include <algorithm>
#include "strings.h"

#include "todo_server.h"

// Arguments:
// todo <command> [args]
// supported commands:
// - add
// - view
// - edit
// - finish
// - delete
// - list


int main(int argc, char **argv) 
{
    if (argc < 2)
    {
        std::cout << usage_string << std::endl;
        return 1;
    }

    std::string command = argv[1];
    auto cmd_loc = std::find(commands.begin(), commands.end(), command);
    if (cmd_loc == std::end(commands))
    {
        std::cout << commands_string << std::endl;
        return 1;
    }

    TodoServer server;

    if (command == "add")
    {

    }
    else if (command == "view")
    {

    }
    else if (command == "edit")
    {

    }
    else if (command == "finish")
    {

    }
    else if (command == "list")
    {

    }
    else {
        std::cout << "Command " << command << " not yet implemented!" << std::endl;
    }

    return 0;
}