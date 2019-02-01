#include "list_todos.h"


namespace TodoLister
{
    void print_all_todos(TodoServer &server)
    {
        const std::vector<TodoObject *> todos = server.get_todo_list();
        for (TodoObject *todo: todos)
        {
            std::cout << *(todo) << std::endl;
        }
    }
} 
