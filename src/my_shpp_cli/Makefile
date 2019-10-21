# ------------------------------------------------
# Adapted from a Generic Makefile 
# by yanick.rochon@gmail.com
# ------------------------------------------------

TARGET   = my_cli

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

CC       = g++
INCLUDE	 = -Iinclude
LFLAGS   = -lreadline -lshpp -Llib
CFLAGS   = -std=c++11 -fPIC -Wall $(INCLUDE) $(LFLAGS) -g

LINKER   = g++ -o


SOURCES := $(wildcard $(SRCDIR)/*)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%=$(OBJDIR)/%.o)
rm = rm -f

export

all: $(BINDIR)/$(TARGET)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

#$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR) 
#	$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/% | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) lib/libshpp.so -lreadline -o $(TARGET)
#	$(CC) -std=c++11 -Wl,-rpath=$(shell pwd)/$(BINDIR) $(INCLUDE) src/main.cpp -o $(BINDIR)/example -L$(BINDIR) -lshpp $(LIBS)


clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)

