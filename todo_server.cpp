#include "todo_server.h"

using namespace std;

class TodoDiskReader {
private:
    string filename;
    ofstream file_output;
public:
    TodoDiskReader()
    {
        std::string homedir = getenv("HOME");
        this->filename = homedir + "/.todo/todo_list.txt";
        ifstream todofile(filename.c_str());
        if (!todofile.good())
        {
            cout << "Error opening file!" << endl;
            exit(1);
        }
    }
    string read()
    {
        if (this->filename.size() == 0) {
            return "";
        }

        // attempt to read data from ~/.todo/todos.txt
        ifstream todo_file(this->filename.c_str());
        stringstream result;

        result << todo_file.rdbuf();
        return result.str();
    }
    void start_save()
    {
        file_output = ofstream(this->filename.c_str());
    }
    void write(string s)
    {
        if (this->filename.size() == 0) 
        {
            return;
        }

        // write data back to ~/.todo/todos.txt
        this->file_output << s;
    }
    void finish()
    {
        file_output.close();
    }
};

TodoServer::TodoServer()
{
    debug_print("Initializing Server...");
    TodoDiskReader reader;
    string line;
    stringstream myfile = stringstream(reader.read());
    while (getline(myfile, line))
    {
        debug_print("Read line " + line + " from file");
        string tokens[3];
        istringstream ss(line);
        int token_loc = 0;
        while (getline(ss, tokens[token_loc], '|'))
        {
            token_loc++;
        }

        string title = tokens[0];
        string description = tokens[1];

        bool completed;
        istringstream(tokens[2]) >> completed;

        TodoObject *todo = new TodoObject(title, description, completed);

        debug_print("Found todo item " + title);

        // add it to the list of todos
        add_todo_item(todo);
    }
}

void TodoServer::remove_todo_item(std::string title)
{
    debug_print("attempting to delete todo " + title);
    std::vector<TodoObject *>::iterator todo_iterator = todos.begin();
    for (auto todo : todos)
    {
        if (todo->get_title().compare(title) == 0)
        {
            debug_print("Found todo " + title);
            todos.erase(todo_iterator);
            return;
        }
        todo_iterator++;
    }
    std::cout << "Couldn't find a todo with the title " << title << std::endl;
}

void TodoServer::add_todo_item(TodoObject *todo)
{
    //todo check dups
    debug_print("Adding todo item " + todo->get_title());
    todos.push_back(todo);
}

void TodoServer::save_todo_list()
{
    TodoDiskReader reader;
    reader.start_save();
    for (TodoObject *todo : todos)
    {
        std::stringstream stream;
        stream << todo;
        reader.write(stream.str());
        debug_print("wrote " + stream.str());
        delete todo;
    }
    reader.finish();
}

TodoObject *TodoServer::find_todo(std::string title)
{
    for (auto todo : todos)
    {
        if (todo->get_title().compare(title) == 0)
        {
            return todo;
        }
    }

    return nullptr;
}

const std::vector<TodoObject *>& TodoServer::get_todo_list()
{
    return todos;
}