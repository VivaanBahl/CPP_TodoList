#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "todo_object.h"

class TodoServer
{
public:
    TodoServer();

    void add_todo_item(TodoObject *todo);
    void remove_todo_item(std::string title);
    void change_todo_title(std::string old_title, std::string new_title);
    void change_todo_description(std::string title, std::string new_description);
    void save_todo_list();
private:
    std::vector<TodoObject *> todos;
};