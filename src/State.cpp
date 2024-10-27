// State.cpp
#include "State.h"

// Constructor
State::State(const std::string& id) : id(id) {}

// Returns the state ID
std::string State::getId() const {
    return id;
}
