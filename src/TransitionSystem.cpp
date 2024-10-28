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

// Helper function to evaluate if a state satisfies the proposition
bool TransitionSystem::evaluateInvariant(const State& state, const Proposition& invariant) {
    return invariant.evaluate(state);
}

// Verifies if the invariant holds for all reachable states from the initial state
bool TransitionSystem::verifyInvariant(const Proposition& invariant) {
    std::unordered_set<State> visitedStates;
    std::stack<State> stack;

    // Starting from the first state as the initial state
    if (states.empty()) {
        return true;  // No states to check, so trivially true
    }

    stack.push(states[0]);
    visitedStates.insert(states[0]);

    while (!stack.empty()) {
        State current = stack.top();
        stack.pop();

        // Check if the current state satisfies the invariant
        if (!evaluateInvariant(current, invariant)) {
            return false;  // Invariant violated
        }

        // Explore all transitions from the current state
        for (const Transition& transition : transitions) {
            if (transition.getSource() == current) {
                State nextState = transition.getDestination();

                // If the next state has not been visited, add it to the stack
                if (visitedStates.find(nextState) == visitedStates.end()) {
                    stack.push(nextState);
                    visitedStates.insert(nextState);
                }
            }
        }
    }

    return true;  // All reachable states satisfy the invariant
}
