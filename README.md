# Transition System Invariant Verifier

This project is a C++ application for defining and verifying invariants within transition systems. It leverages classes to represent logical formulas, propositions, states, transitions, and transition systems, ultimately allowing the verification of invariants over reachable states in a transition system.

## Project Structure

The project has the following directory structure:

```
root
├── include/ # Header files
│ ├── LogicalFormula.h
│ ├── Proposition.h
│ ├── State.h
│ ├── Transition.h
│ └── TransitionSystem.h
├── src/ # Implementation files
│ ├── LogicalFormula.cpp
│ ├── Proposition.cpp
│ ├── State.cpp
│ ├── Transition.cpp
│ └── TransitionSystem.cpp
└── main.cpp # Entry point of the program
```

## Classes Overview

-   **LogicalFormula**: Represents logical expressions that combine propositions using `AND`, `OR`, and `NOT` operators.
-   **Proposition**: Defines a basic logical statement with a specific value and comparison operator (e.g., `EQUAL`, `GREATER`).
-   **State**: Represents a state within the system, identified by an ID and associated propositions.
-   **Transition**: Models transitions between states, with a condition (logical formula) determining when the transition is valid.
-   **TransitionSystem**: Manages states and transitions, providing methods to add new states and transitions and verify if a specific invariant holds across all reachable states.

## Installation and Compilation

### Prerequisites

-   C++ compiler supporting C++11 or later.
-   CMake (optional, for build management).

### Compilation

A `Makefile` can be created to automate compilation:

```bash
# Navigate to the project root directory
make
```

Alternatively, compile manually:

```bash
# From the project root directory
g++ main.cpp src/*.cpp -o transition_system_verifier
```

### Running the Program

After compilation, execute the program as follows:

```bash
./transition_system_verifier
```

## Usage

In `main.cpp`, you can define states, transitions, and invariants for the transition system. The project allows:

1. **Defining States** with unique IDs and propositions.
2. **Defining Transitions** between states with conditions specified by logical formulas.
3. **Verifying Invariants** across all reachable states in the system.

The main purpose is to ensure that a user-defined invariant holds true across all states reachable from the initial state.

### Example

```cpp
// Define a few states
State s1("state1", {{"x", 10}});
State s2("state2", {{"x", 20}});

// Define a proposition and an invariant
Proposition p("x", 10, Operator::GREATER_OR_EQUAL);
TransitionSystem ts;
ts.addState(s1);
ts.addState(s2);

// Add transitions
LogicalFormula condition(std::make_shared<Proposition>(p));
ts.addTransition(Transition(s1, s2, condition));

// Verify the invariant
bool result = ts.verifyInvariant(p);
std::cout << "Invariant holds: " << std::boolalpha << result << std::endl;
```

## Testing

Run the example code in `main.cpp` to observe the invariant verification. Modify `main.cpp` to test different configurations of states, transitions, and propositions as needed.

## Design Considerations

The project is structured for modularity and extensibility, with a clear separation of concerns:

1. **Transition System Representation**: States and transitions are encapsulated in dedicated classes.
2. **Logical Formulas and Propositions**: Supports complex logical expressions, enabling flexible invariant conditions.
3. **Invariant Verification**: Utilizes a stack-based approach to verify reachability and invariant satisfaction across all states.
