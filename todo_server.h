#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "todo_object.h"
#include "debug_utils.h"

#ifndef TODO_SERVER_H
#define TODO_SERVER_H
class TodoServer
{
public:
    TodoServer();

    void add_todo_item(TodoObject *todo);
    void remove_todo_item(std::string title);
    void save_todo_list();
    const std::vector<TodoObject *>& get_todo_list();
    TodoObject *find_todo(std::string title);
private:
    std::vector<TodoObject *> todos;
};
#endif