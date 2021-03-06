#include "todo_object.h"

std::string TodoObject::get_title()
{
    return title;
}

std::string TodoObject::get_description()
{
    return description;
}

bool TodoObject::get_completed()
{
    return completed;
}

void TodoObject::set_title(std::string new_title)
{
    this->title = new_title;
}

void TodoObject::set_description(std::string new_description)
{
    this->description = new_description;
}

void TodoObject::set_completed(bool new_completed)
{
    this->completed = new_completed;
}

// This one is a prettier print
std::ostream& operator<< (std::ostream &out, const TodoObject &todo)
{
    out << (todo.completed ? "X" : "0") << " | " << todo.title << " : " << todo.description;
    return out;

}

// this one is more for serialization
std::ostream& operator<< (std::ostream &out, const TodoObject *todo)
{
    out << todo->title << "|" << todo->description << "|" << (todo->completed ? "1" : "0") << std::endl;
    return out;
}

std::string TodoObject::get_pretty_print_string()
{
    int title_len = this->title.size();
    std::stringstream separator;
    std::stringstream padding;
    int pad_length = 5;
    for (int i = 0; i < title_len + pad_length; i++)
    {
        separator << "-";
    }
    for (int i = 0; i < pad_length - 1; i++)
    {
        padding << " ";
    }
    
    return "\n" + this->title + padding.str() + (this->completed ? "X" : "O") + "\n" + separator.str() + "\n\n" + this->description + "\n";
}

TodoObject::TodoObject(std::string title, std::string description, bool completed)
{
    this->title = title;
    this->description = description;
    this->completed = completed;
}
