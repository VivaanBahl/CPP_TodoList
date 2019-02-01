#include "list_todos.h"


namespace TodoLister
{
    void print_all_todos(TodoServer &server)
    {
        const std::vector<TodoObject *> todos = server.get_todo_list();
        for (TodoObject *todo: todos)
        {
            std::string completed_str = todo->get_completed() ? "X" : "O";
            std::string title = todo->get_title();

            std::cout << completed_str << " | " << title << std::endl;
        }
    }
} 
