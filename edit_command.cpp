#include "edit_command.h"

namespace EditorParser
{
    void parse_command_args(TodoServer &server, char **command_args)
    {
        // ./todo edit <title> <"title"|"desc"> <replacement>
        std::string todo_title = command_args[0];
        std::string repl_type = command_args[1];
        std::string repl_str = command_args[2];

        // find todo
        TodoObject *todo = server.find_todo(todo_title);
        if (todo == nullptr)
        {
            std::cout << "Couldn't find todo titled " << todo_title << std::endl;
            return;
        }

        TodoEditor editor;

        // parse type
        if (repl_type.compare("title") == 0)
        {
            editor = TodoTitleEditor();
        }
        else if (repl_type.compare("desc") == 0)
        {
            editor = TodoDescEditor();
        }
        else
        {
            std::cout << "Please specify \"title\" or \"desc\"" << std::endl;
        }
        
    }
};

void TodoEditor::replace(TodoObject *todo, std::string replacement)
{

}

void TodoTitleEditor::replace(TodoObject *todo, std::string replacement)
{

}

void TodoDescEditor::replace(TodoObject *todo, std::string replacement)
{

}
