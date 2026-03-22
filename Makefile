TARGET = main
RM = rm -rf
FixPath = $1

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude $(shell wx-config --cxxflags)
LDFLAGS = $(shell wx-config --libs richtext,core,base)

SRC = $(wildcard src/*.cpp) $(wildcard src/view/*.cpp) $(wildcard src/model/*.cpp) $(wildcard src/controller/*.cpp) $(wildcard src/classes/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(call FixPath, $(OBJ) $(TARGET))

.PHONY: all clean
