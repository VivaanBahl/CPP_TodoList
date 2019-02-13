
#include "todo_object.h"
#include "todo_server.h"
#include <string>

#ifndef TODO_EDITOR_H
#define TODO_EDITOR_H

namespace EditorParser
{
    void parse_command_args(TodoServer &server, char **command_args);
};

class TodoEditor
{
public:
    virtual void replace(TodoObject *todo, std::string replacement);
};

class TodoTitleEditor : TodoEditor
{
};

class TodoDescEditor : TodoEditor
{
};

#endif