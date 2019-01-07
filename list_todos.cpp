#include "list_todos.h"


namespace TodoLister
{
    void print_all_todos(TodoServer &server)
    {
        const std::vector<TodoObject *> todos = server.get_todo_list();
        for (TodoObject *todo: todos)
        {
            std::string completed_str = todo->get_completed() ? "0" : "O";
            std::string title = todo->get_title();
            std::string description = todo->get_description();

            std::cout << completed_str << " | " << title << " : " << description << std::endl;
        }
    }
} 