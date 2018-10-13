#include "todo_server.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

TodoServer::TodoServer()
{
    // attempt to read data from ~/.todo/todos.txt
    string line;
    ifstream todo_file("~/.todo/todos.txt");
    if (todo_file.is_open())
    {
        while (getline(todo_file, line))
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
}