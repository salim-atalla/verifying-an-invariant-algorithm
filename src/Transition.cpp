// Transition.cpp
#include "Transition.h"

// Constructor
Transition::Transition(const State& source, const State& destination, const LogicalFormula& condition)
    : source(source), destination(destination), condition(condition) {}

// Returns the source state
State Transition::getSource() const {
    return source;
}

// Returns the destination state
State Transition::getDestination() const {
    return destination;
}

// Returns the condition for the transition
LogicalFormula Transition::getCondition() const {
    return condition;
}
