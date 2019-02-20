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
            editor.edit(todo, TodoEditor::EDIT_TITLE, repl_str);
        }
        else if (repl_type.compare("desc") == 0)
        {
            editor.edit(todo, TodoEditor::EDIT_DESC, repl_str);
        }
        else
        {
            std::cout << "Please specify \"title\" or \"desc\"" << std::endl;
        }
        
    }
};

void TodoEditor::edit(TodoObject *todo, int edit_type, std::string replacement)
{
    TodoTitleEditor title_editor;
    TodoDescEditor desc_editor;
    switch (edit_type)
    {
        case TodoEditor::EDIT_TITLE:
            /* code */
            title_editor.replace(todo, replacement);
            break;
        
        case TodoEditor::EDIT_DESC:
            desc_editor.replace(todo, replacement);
            break;
    
        default:
            break;
    }
}

void TodoEditor::replace(TodoObject *todo, std::string replacement)
{
    std::cout << "Uh oh for " << todo->get_title() << " -> " << replacement << std::endl;
}

void TodoTitleEditor::replace(TodoObject *todo, std::string replacement)
{
    todo->set_title(replacement);
}

void TodoDescEditor::replace(TodoObject *todo, std::string replacement)
{
    todo->set_description(replacement);
}
