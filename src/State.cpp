// State.cpp
#include "State.h"

// Constructor
State::State(const std::string& id, const std::unordered_map<std::string, int>& propositions)
    : id(id), propositions(propositions) {}
    
// Returns the state ID
std::string State::getId() const {
    return id;
}

// Sets or updates a proposition value in the state
void State::setPropositionValue(const std::string& name, int value) {
    propositions[name] = value;
}

// Gets the value of a proposition by name
int State::getPropositionValue(const std::string& name) const {
    auto it = propositions.find(name);
    if (it != propositions.end()) {
        return it->second; // Assuming propositions now store integers
    }
    throw std::runtime_error("Proposition not found in state");
}