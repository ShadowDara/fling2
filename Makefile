# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Zielprogramm
TARGET = fling

# Quellcode-Dateien
SRCS = src/main.cpp src/ast.cpp src/lexer.cpp src/parser.cpp

# Objektdateien (automatisch von SRCS abgeleitet)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./fling

.PHONY: all clean
