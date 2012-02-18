TARGET   = tutorialmud

OBJFILES = main.o

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
