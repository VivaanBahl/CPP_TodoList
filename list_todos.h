#include "todo_object.h"
#include "todo_server.h"
#include <vector>
#include <string>

#ifndef TODO_LISTER_H
#define TODO_LISTER_H
namespace TodoLister
{
    void print_all_todos(TodoServer &server);
}
#endif