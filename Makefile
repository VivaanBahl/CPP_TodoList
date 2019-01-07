COMPILER=g++
COMPILER_OPTIONS = -std=c++11 -Wall -Wextra
SOURCE_FILES = debug_utils.cpp todo_server.cpp todo_object.cpp list_todos.cpp add_parser.cpp main.cpp
OUTPUT_FILE = todo_local

all:
	$(COMPILER) $(COMPILER_OPTIONS) $(SOURCE_FILES) -o $(OUTPUT_FILE)

clean:
	rm -rf todo_local