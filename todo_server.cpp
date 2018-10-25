#include "todo_server.h"

using namespace std;

class TodoDiskReader {
private:
    string filename;
public:
    TodoDiskReader(string filename)
    {
        this->filename = filename;
        ifstream todofile(filename.c_str());
        if (!todofile.good())
        {
            // create the file
            ofstream todocreate(filename.c_str());
            todocreate << "";
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
    void write(string s)
    {
        if (this->filename.size() == 0) 
        {
            return;
        }

        // write data back to ~/.todo/todos.txt
        ofstream todo_file(this->filename.c_str());
        todo_file << s;
    }
};

TodoServer::TodoServer()
{
    TodoDiskReader reader("~/.todo/todo_list.txt");
    string line;
    while (getline(stringstream(reader.read()), line))
    {
        string tokens[3];
        istringstream ss(line);
        int token_loc = 0;
        while (getline(ss, tokens[token_loc], '|'))
        {
            token_loc++;
        }

        bool completed;
        istringstream(tokens[2]) >> completed;
    }
}