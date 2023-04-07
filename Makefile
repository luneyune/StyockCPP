CFLAGS = -Wall -Werror -I src -g -O0
CC = g++

Executable_dir = bin
Objects_app_dir = obj/app
Objects_test_dir = obj/test
Sources_app_dir = src
Sources_test_dir = test

.PHONY: all run format test

all: $(Executable_dir)/main

#Executables
$(Executable_dir)/main: $(Objects_app_dir)/main.o $(Objects_app_dir)/input.o $(Objects_app_dir)/command.o $(Objects_app_dir)/compiler.o $(Objects_app_dir)/programm.o
	$(CC) $^ $(CFLAGS) -o $@

#App objects
$(Objects_app_dir)/main.o: $(Sources_app_dir)/main.cpp $(Sources_app_dir)/input.hpp $(Sources_app_dir)/compiler.hpp $(Sources_app_dir)/command.hpp $(Sources_app_dir)/types.hpp
	$(CC) $< $(CFLAGS) -c -o $@
$(Objects_app_dir)/input.o: $(Sources_app_dir)/input.cpp $(Sources_app_dir)/input.hpp
	$(CC) $< $(CFLAGS) -c -o $@
$(Objects_app_dir)/compiler.o: $(Sources_app_dir)/compiler.cpp $(Sources_app_dir)/compiler.hpp
	$(CC) $< $(CFLAGS) -c -o $@
$(Objects_app_dir)/command.o: $(Sources_app_dir)/command.cpp $(Sources_app_dir)/command.hpp
	$(CC) $< $(CFLAGS) -c -o $@
$(Objects_app_dir)/programm.o: $(Sources_app_dir)/programm.cpp $(Sources_app_dir)/programm.hpp
	$(CC) $< $(CFLAGS) -c -o $@



run: $(Executable_dir)/main
	$(Executable_dir)/main
clean:
	rm -f $(Objects_app_dir)/*.o
	rm -f $(Executable_dir)/main
