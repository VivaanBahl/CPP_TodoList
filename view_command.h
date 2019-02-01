#include "todo_object.h"
#include "todo_server.h"
#include <string>

#ifndef VIEW_CMD_H
#define VIEW_CMD_H

class ViewCommand
{
    static void view_todo(TodoObject *to_view);
public:
    static void parse_command(char **args, TodoServer &server);
};

#endif