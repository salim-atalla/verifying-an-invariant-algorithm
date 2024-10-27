// TransitionSystem.h
#ifndef TRANSITIONSYSTEM_H
#define TRANSITIONSYSTEM_H

#include <vector>
#include <string>
#include "State.h"
#include "Transition.h"

// Manages states and transitions in a transition system
class TransitionSystem {
public:
    // Adds a new state to the system
    void addState(const State& state);

    // Adds a new transition to the system
    void addTransition(const Transition& transition);

    // Getters for states and transitions
    const std::vector<State>& getStates() const;
    const std::vector<Transition>& getTransitions() const;

private:
    std::vector<State> states;       // Collection of states
    std::vector<Transition> transitions; // Collection of transitions
};

#endif // TRANSITIONSYSTEM_H
