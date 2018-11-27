#include "add_parser.h"

namespace AddParser
{
    TodoObject parse_command_args(char **full_argv)
    {
        std::string title = full_argv[2];
        std::string description = full_argv[3];

        return TodoObject(title, description, false);
    }
}