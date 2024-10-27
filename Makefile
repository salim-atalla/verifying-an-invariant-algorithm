# Name of the executable
TARGET = main

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Source files and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler and flags
CXX = g++
CXXFLAGS = -I$(INC_DIR) -std=c++17 -Wall
LDFLAGS =

# Default rule to build the executable
all: $(TARGET)

# Linking step to create the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compiling each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the object files directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean rule to remove generated files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
