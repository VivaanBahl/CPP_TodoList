#include "finish_parser.h"

void Finisher::complete(TodoObject *todo)
{
    todo->set_completed(true);
}

void Unfinisher::uncomplete(TodoObject *todo)
{
    todo->set_completed(false);
}

TodoObject* FinishUnfinish::find_todo(char **cmd_args, TodoServer &server)
{
    std::string title = cmd_args[0];
    auto todo_list = server.get_todo_list();
    for (auto todo : todo_list)
    {
        if (todo->get_title().compare(title) == 0)
        {
            return todo;
        }
    }

    std::cout << "Couldn't find todo with title " << title << std::endl;
    return nullptr;

}