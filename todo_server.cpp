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

void TodoServer::add_todo_item(TodoObject *todo)
{
    debug_print("Adding todo item " + todo->get_title());
    todos.push_back(todo);
}

void TodoServer::save_todo_list()
{
    TodoDiskReader reader;
    reader.start_save();
    for (TodoObject *todo : todos)
    {
        std::string todo_string = todo->serialize();
        reader.write(todo_string);
        debug_print("wrote " + todo_string);
        delete todo;
    }
    reader.finish();
}

const std::vector<TodoObject *>& TodoServer::get_todo_list()
{
    return todos;
}