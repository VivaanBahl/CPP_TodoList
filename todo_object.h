#include <string>
#include <sstream>
#include <iostream>

#ifndef TODO_OBJECT_H
#define TODO_OBJECT_H
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

    std::string serialize();
    std::string get_pretty_print_string();

    void set_title(std::string new_title);
    void set_description(std::string new_description);
    void set_completed(bool new_completed);

    TodoObject(std::string title, std::string description, bool completed = false);
};
#endif