TARGET=main

SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_DIR=.
CC=g++
CFLAGS= -pedantic -Wall -Werror -Wconversion -ansi -std=c++03  -g -I$(INC_DIR)
CXXFLAGS=$(CFLAGS)
LDFLAGS= -g

.PHONY: clean run gdb leak

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)


include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)
leak: $(TARGET)
	valgrind ./$(TARGET) --leak-check=full
