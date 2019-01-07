/**
 * To-Do list command line app
 */

#include <iostream>
#include <stdint.h>
#include <algorithm>
#include "strings.h"

#include "add_parser.h"
#include "todo_server.h"
#include "list_todos.h"
#include "debug_utils.h"

// Arguments:
// todo <command> [args]
// supported commands:
// - add
// - view
// - edit
// - finish
// - unfinish
// - delete
// - list
static const int num_args_add = 4;
static const int num_args_view = 3;
static const int num_args_edit = 5;
static const int num_args_finish = 3;
static const int num_args_unfinish = 3;
static const int num_args_delete = 3;
static const int num_args_list = 2;

int main(int argc, char **argv) 
{
    if (argc < 2)
    {
        std::cout << CLIStrings::usage_string << std::endl;
        return 1;
    }

    // read in the todos from the todo file
    TodoServer server;

    std::string command = argv[1];
    auto cmd_loc = std::find(CLIStrings::commands.begin(), CLIStrings::commands.end(), command);
    if (cmd_loc == std::end(CLIStrings::commands))
    {
        std::cout << CLIStrings::commands_string << std::endl;
        return 1;
    }

    char **command_args = (char **) malloc(sizeof(char*) * (argc - 2));
    for (int i = 2; i < argc; i++)
    {
        command_args[i-2] = argv[i];
    }

    if (command == "add")
    {
        debug_print("Add command");
        if (argc != num_args_add)
        {
            std::cout << CLIStrings::add_string << std::endl;
            return 1;
        }
        TodoObject *to_add = AddParser::parse_command_args(command_args);
        server.add_todo_item(to_add);
    }
    else if (command == "view")
    {
        if (argc != num_args_view)
        {
            std::cout << CLIStrings::view_string << std::endl;
            return 1;
        }
    }
    else if (command == "edit")
    {
        if (argc != num_args_edit)
        {
            std::cout << CLIStrings::edit_string << std::endl;
            return 1;
        }
    }
    else if (command == "finish")
    {
        if (argc != num_args_finish)
        {
            std::cout << CLIStrings::finish_string << std::endl;
            return 1;
        }
    }
    else if (command == "unfinish")
    {
        if (argc != num_args_unfinish)
        {
            std::cout << CLIStrings::unfinish_string << std::endl;
            return 1;
        }
    }
    else if (command == "delete")
    {
        if (argc != num_args_delete)
        {
            std::cout << CLIStrings::delete_string << std::endl;
            return 1;
        }
    }
    else if (command == "list")
    {
        debug_print("List command");
        if (argc != num_args_list)
        {
            std::cout << CLIStrings::list_string << std::endl;
            return 1;
        }

        TodoLister::print_all_todos(server);
    }
    else {
        std::cout << "Command " << command << " not yet implemented!" << std::endl;
    }

    return 0;
}