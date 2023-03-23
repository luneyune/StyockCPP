CFLAGS = -Wall -Werror -I src
CC = g++

Executable_dir = bin
Objects_app_dir = obj/app
Objects_test_dir = obj/test
Sources_app_dir = src
Sources_test_dir = test

all: $(Executable_dir)/main

.PHONY: all run format test

#Executables
$(Executable_dir)/main: $(Objects_app_dir)/main.o $(Objects_app_dir)/input.o
	$(CC) $^ $(CFLAGS) -o $@

#App objects
$(Objects_app_dir)/main.o: $(Sources_app_dir)/main.cpp $(Sources_app_dir)/input.hpp
	$(CC) $< $(CFLAGS) -c -o $@
$(Objects_app_dir)/input.o: $(Sources_app_dir)/input.cpp $(Sources_app_dir)/input.hpp
	$(CC) $< $(CFLAGS) -c -o $@


run: $(Executable_dir)/main
	$(Executable_dir)/main
clean:
	rm -f $(Objects_app_dir)/*.o
	rm -f $(Executable_dir)/main
