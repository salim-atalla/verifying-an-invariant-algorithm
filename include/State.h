// State.h
#ifndef STATE_H
#define STATE_H

#include <string>

// Represents a state in the transition system
class State {
public:
    // Constructor
    State(const std::string& id);

    // Getter for the state ID
    std::string getId() const;

private:
    std::string id; // Unique identifier for the state
};

#endif // STATE_H
