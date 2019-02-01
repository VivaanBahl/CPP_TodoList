#include "view_command.h"

void ViewCommand::view_todo(TodoObject *to_view)
{
    std::string full_string = to_view->get_pretty_print_string();
    printf("%s\n", full_string.c_str());
}

void ViewCommand::parse_command(char **args, TodoServer &server)
{
    std::string title = args[0];
    auto todo_list = server.get_todo_list();

    for (auto todo : todo_list)
    {
        if (todo->get_title().compare(title) == 0)
        {
            view_todo(todo);
            return;
        }
    }

    printf("Couldn't find todo titled %s\n", title.c_str());
}