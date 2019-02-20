
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
    void edit(TodoObject *todo, int edit_type, std::string replacement);

    static const int EDIT_TITLE = 0;
    static const int EDIT_DESC = 1;
};

class TodoTitleEditor : TodoEditor
{
public:
    void replace(TodoObject *todo, std::string replacement) override;
};

class TodoDescEditor : TodoEditor
{
public:
    void replace(TodoObject *todo, std::string replacement) override;
};

#endif