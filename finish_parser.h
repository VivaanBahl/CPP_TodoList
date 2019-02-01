#include <string>
#include "todo_object.h"
#include "todo_server.h"

#ifndef FINISH_PARSER_H
#define FINISH_PARSER_H

class Finisher
{
public:
    void complete(TodoObject *todo);
};

class Unfinisher
{
public:
    void uncomplete(TodoObject *todo);
};

class FinishUnfinish : public Finisher, public Unfinisher
{
public:
    TodoObject* find_todo(char **cmd_args, TodoServer &server);
};

#endif