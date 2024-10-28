// State.cpp
#include "State.h"

// Constructor
State::State(const std::string& id, const std::unordered_map<std::string, bool>& propositions)
    : id(id), propositions(propositions) {}
    
// Returns the state ID
std::string State::getId() const {
    return id;
}

// Sets or updates a proposition value in the state
void State::setPropositionValue(const std::string& name, bool value) {
    propositions[name] = value;
}

// Gets the value of a proposition by name
bool State::getPropositionValue(const std::string& name) const {
    auto it = propositions.find(name);
    if (it != propositions.end()) {
        return it->second;
    }
    // Return false or throw an exception if the proposition does not exist
    throw std::runtime_error("Proposition not found in state");
}