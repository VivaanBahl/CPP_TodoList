#include "finish_parser.h"

void Finisher::complete(TodoObject *todo)
{
    todo->set_completed(true);
    std::cout << "Marked todo " << todo->get_title() << "as completed" << std::endl;
}

void Unfinisher::uncomplete(TodoObject *todo)
{
    todo->set_completed(false);
    std::cout << "Marked todo " << todo->get_title() << "as incomplete" << std::endl;
}

TodoObject* FinishUnfinish::find_todo(char **cmd_args, TodoServer &server)
{
    std::string title = cmd_args[0];
    return server.find_todo(title);

}