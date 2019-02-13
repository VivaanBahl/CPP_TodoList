#include <vector>
#include <string>

namespace CLIStrings
{
    static const std::vector<std::string> commands = {"add", "view", "edit", "finish", "unfinish", "delete", "list"};
    static const std::string usage_string = "Usage: todo <command> [command_args]";
    static const std::string commands_string = 
    "Commands:\n \
    \tadd\t\tAdd a todo item\n \
    \tview\t\tView details about a todo item\n \
    \tedit\t\tEdit a todo item\n \
    \tfinish\t\tMark a todo item as completed\n \
    \tunfinish\tMark a todo item as not completed\n \
    \tdelete\t\tDelete a todo item\n \
    \tlist\t\tList todo items\n";
    static const std::string add_string = "Usage: todo add <title> <description>";
    static const std::string view_string = "Usage: todo view <title>";
    static const std::string edit_string = "Usage: todo edit <title> <\"title\"|\"desc\"> <replacement>";
    static const std::string finish_string = "Usage: todo finish <title>";
    static const std::string unfinish_string = "Usage: todo unfinish <title>";
    static const std::string delete_string = "Usage: todo delete <title>";
    static const std::string list_string = "Usage: todo list";
}