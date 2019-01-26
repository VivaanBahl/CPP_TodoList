#include "add_parser.h"

namespace AddParser
{
    TodoObject* parse_command_args(char **add_args)
    {
        std::string title = add_args[0];
        std::string description = add_args[1];

        return new TodoObject(title, description);
    }
}