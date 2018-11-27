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

TodoObject::TodoObject(std::string title, std::string description, bool completed)
{
    this->title = title;
    this->description = description;
    this->completed = completed;
}
