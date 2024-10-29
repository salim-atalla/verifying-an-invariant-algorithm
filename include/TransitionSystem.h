#ifndef TRANSITIONSYSTEM_H
#define TRANSITIONSYSTEM_H

#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include "State.h"
#include "Transition.h"
#include "Proposition.h"



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

    // Verifies if the invariant holds for all reachable states
    bool verifyInvariant(const Proposition& invariant);

    // Helper function to evaluate if a state satisfies a proposition
    bool evaluateInvariant(const State& state, const Proposition& invariant);

private:
    std::vector<State> states;
    std::vector<Transition> transitions;
};

#endif // TRANSITIONSYSTEM_H
