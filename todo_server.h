#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class TodoObject
{
private:
    std::string title;
    std::string description;
    bool completed;
public:
    std::string get_title();
    std::string get_description();
    bool get_completed();

    void set_title(std::string new_title);
    void set_description(std::string new_description);
    void set_completed(bool new_completed);

    TodoObject(std::string title, std::string description, bool completed);
};

class TodoServer
{
public:
    TodoServer();

    void add_todo_item(TodoObject todo);
    void remove_todo_item(std::string title);
    void change_todo_title(std::string old_title, std::string new_title);
    void change_todo_description(std::string title, std::string new_description);
    void save_todo_list();
};