#include "Proposition.h"

// Constructor for Proposition
Proposition::Proposition(const std::string &name, bool value) : name(name), value(value) {}

// Returns the name of the proposition
std::string Proposition::getName() const {
    return name;
}

// Returns the truth value of the proposition
bool Proposition::getValue() const {
    return value;
}

// Sets the truth value of the proposition
void Proposition::setValue(bool value) {
    this->value = value;
}

// Evaluates if the state satisfies this proposition
bool Proposition::evaluate(const State& state) const {
    // Assuming `State` has a method `getPropositionValue` to retrieve the value of a proposition
    // by name (e.g., bool State::getPropositionValue(const std::string& propName) const;)
    return state.getPropositionValue(name) == value;
}
