#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "include/TransitionSystem.h"
#include "include/State.h"
#include "include/Proposition.h"
#include "include/Transition.h"

// Assume State class has a method getAttributes to access attribute map
// Assume Proposition class has a method evaluate that takes a State as parameter

int main() {
    // Example 1: Mutual exclusion with a binary semaphore
    std::cout << "Example 1: Mutual exclusion with binary semaphore\n";

    // Creating a transition system for mutual exclusion
    TransitionSystem mutexSystem;

    // States representing two concurrent processes
    State idleState("Idle", {{"semaphore", 1}, {"process1", 0}, {"process2", 0}}); // semaphore = 1: free
    State criticalProcess1("CriticalProcess1", {{"semaphore", 0}, {"process1", 1}, {"process2", 0}});
    State criticalProcess2("CriticalProcess2", {{"semaphore", 0}, {"process1", 0}, {"process2", 1}});

    // Adding states to the system
    mutexSystem.addState(idleState);
    mutexSystem.addState(criticalProcess1);
    mutexSystem.addState(criticalProcess2);

    // Transitions for entering and exiting the critical section
    Transition enterProcess1(idleState, criticalProcess1, LogicalFormula());    // Process1 enters critical section
    Transition exitProcess1(criticalProcess1, idleState, LogicalFormula());     // Process1 exits critical section
    Transition enterProcess2(idleState, criticalProcess2, LogicalFormula());    // Process2 enters critical section
    Transition exitProcess2(criticalProcess2, idleState, LogicalFormula());     // Process2 exits critical section

    // Adding transitions to the system
    mutexSystem.addTransition(enterProcess1);
    mutexSystem.addTransition(exitProcess1);
    mutexSystem.addTransition(enterProcess2);
    mutexSystem.addTransition(exitProcess2);

    // Mutual exclusion proposition: semaphore must be 0 when a process is in the critical section
    Proposition mutualExclusion("semaphore", 0, Operator::EQUAL);

    // Checking mutual exclusion invariant
    bool invariantSatisfied = true;
    for (const auto& state : mutexSystem.getStates()) {
        // Only check mutual exclusion in critical section states
        if (state.getPropositionValue("process1") == 1 || state.getPropositionValue("process2") == 1) {
            if (!mutexSystem.evaluateInvariant(state, mutualExclusion)) {
                std::cout << "Mutual exclusion not satisfied for state: " << state.getId() << std::endl;
                invariantSatisfied = false;
            } else {
                std::cout << "Mutual exclusion satisfied for state: " << state.getId() << std::endl;
            }
        }
    }

    if (invariantSatisfied) {
        std::cout << "All states satisfy mutual exclusion.\n" << std::endl;
    } else {
        std::cout << "At least one state does not satisfy mutual exclusion.\n" << std::endl;
    }

    // Example 2: Counter system with minimum bound
    std::cout << "Example 2: Counter system\n";

    TransitionSystem counterSystem;

    // States of the counter
    State counterZero("CounterZero", {{"counter", 0}});
    State counterPositive("CounterPositive", {{"counter", 1}});
    State counterNegative("CounterNegative", {{"counter", -1}}); // Invalid state for the invariant

    // Adding states to the system
    counterSystem.addState(counterZero);
    counterSystem.addState(counterPositive);
    counterSystem.addState(counterNegative);

    // Transitions for incrementing and decrementing the counter
    Transition increment(counterZero, counterPositive, LogicalFormula());  // Increment counter
    Transition decrement(counterPositive, counterZero, LogicalFormula());  // Decrement counter

    // Adding transitions to the system
    counterSystem.addTransition(increment);
    counterSystem.addTransition(decrement);

    // Proposition: counter should never be negative
    Proposition nonNegativeCounter("counter", 0, Operator::GREATER_EQUAL);

    // Checking invariant for the counter
    invariantSatisfied = true;
    for (const auto& state : counterSystem.getStates()) {
        if (!counterSystem.evaluateInvariant(state, nonNegativeCounter)) {
            std::cout << "Invariant 'counter >= 0' not satisfied for state: " << state.getId() << std::endl;
            invariantSatisfied = false;
        } else {
            std::cout << "Invariant 'counter >= 0' satisfied for state: " << state.getId() << std::endl;
        }
    }

    if (invariantSatisfied) {
        std::cout << "All states satisfy the invariant 'counter >= 0'.\n" << std::endl;
    } else {
        std::cout << "At least one state does not satisfy the invariant 'counter >= 0'.\n" << std::endl;
    }

    return 0;
}
