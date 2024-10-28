CXX = g++
CXXFLAGS = -Iinclude -std=c++17 -Wall

OBJS = obj/main.o obj/TransitionSystem.o obj/State.o obj/Transition.o obj/Proposition.o obj/LogicalFormula.o

# Default target
all: obj $(OBJS)
	$(CXX) -o main $(OBJS)

# Rule to create object files
obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for main.cpp specifically
obj/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o obj/main.o

# Clean target to remove object files and the main executable
clean:
	rm -f obj/*.o main

# Target to create obj directory
obj:
	mkdir -p obj
