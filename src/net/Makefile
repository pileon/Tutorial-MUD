#####################################################################
# File: Makefile                               Part of Tutorial MUD #
#                                                                   #
# Created by Joachim Pileborg <tm@pileborg.org>                     #
# This file is in the public domain.                                #
#####################################################################

TARGET   = net.a

OBJFILES = address.o

CXXFLAGS = -Wall -Wextra -std=c++0x -pipe -g

CXX      = g++

.PHONY: default
default: all

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJFILES)
	ar crv $(TARGET) $(OBJFILES)
	ranlib $(TARGET)

.PHONY: clean
clean:
	-rm -f $(OBJFILES)
	-rm -f $(TARGET)

#####################################################################
# Object file targets

address.o: address.cpp address.h
