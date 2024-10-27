// TransitionSystem.cpp
#include "TransitionSystem.h"

// Adds a new state to the system
void TransitionSystem::addState(const State& state) {
    states.push_back(state);
}

// Adds a new transition to the system
void TransitionSystem::addTransition(const Transition& transition) {
    transitions.push_back(transition);
}

// Returns the collection of states
const std::vector<State>& TransitionSystem::getStates() const {
    return states;
}

// Returns the collection of transitions
const std::vector<Transition>& TransitionSystem::getTransitions() const {
    return transitions;
}
