#####################################################################
# File: Makefile                               Part of Tutorial MUD #
#                                                                   #
# Created by Joachim Pileborg <tm@pileborg.org>                     #
# This file is in the public domain.                                #
#####################################################################

TARGET   = tutorialmud

OBJFILES = main.o logger.o config.o

CXXFLAGS = -Wall -Wextra -std=c++0x -pipe -g
LDFLAGS  = -g

LD       = g++
CXX      = g++

.PHONY: default
default: all

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(LD) $(LDFLAGS) $(OBJFILES) -o $(TARGET)

.PHONY: clean
clean:
	-rm -f $(OBJFILES)
	-rm -f $(TARGET)

#####################################################################
# Object file targets

main.o: main.cpp tm.h logger.h

logger.o: logger.cpp tm.h logger.h

config.o: config.cpp tm.h config.h
