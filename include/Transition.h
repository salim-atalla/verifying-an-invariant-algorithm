// Transition.h
#ifndef TRANSITION_H
#define TRANSITION_H

#include "State.h"
#include "LogicalFormula.h"



// Represents a transition between two states
class Transition {
public:
    // Constructor
    Transition(const State& source, const State& destination, const LogicalFormula& condition);

    // Getters for source, destination, and condition
    State getSource() const;
    State getDestination() const;
    LogicalFormula getCondition() const;

private:
    State source;          // Source state
    State destination;     // Destination state
    LogicalFormula condition; // Condition for the transition
};

#endif // TRANSITION_H
