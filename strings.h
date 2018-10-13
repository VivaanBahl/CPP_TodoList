#include <vector>

static const std::string usage_string = "Usage: todo <command> [command_args]";
static const std::string commands_string = 
"Commands:\n \
\tadd\tAdd a todo item\n \
\tview\tView details about a todo item\n \
\tedit\tEdit a todo item\n \
\tfinish\tMark a todo item as completed\n \
\tdelete\tDelete a todo item\n \
\tlist\tList todo items\n";
static const std::vector<std::string> commands = {"add", "view", "edit", "finish", "delete", "list"};