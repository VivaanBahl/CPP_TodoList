COMPILER=g++
COMPILER_OPTIONS = -std=c++11 -Wall -Wextra
SOURCE_FILES = todo_server.cpp add_todo.cpp main.cpp
OUTPUT_FILE = todo_local

all:
	$(COMPILER) $(COMPILER_OPTIONS) $(SOURCE_FILES) -o $(OUTPUT_FILE)

clean:
	rm -rf todo_local