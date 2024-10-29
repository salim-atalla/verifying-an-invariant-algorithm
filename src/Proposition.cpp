#include "Proposition.h"

// Constructor for Proposition
Proposition::Proposition(const std::string &name, int value, Operator op) : name(name), value(value), op(op) {}

// Returns the name of the proposition
std::string Proposition::getName() const {
    return name;
}

// Returns the truth value of the proposition
int Proposition::getValue() const {
    return value;
}

// Sets the truth value of the proposition
void Proposition::setValue(int value) {
    this->value = value;
}

// Evaluates if the state satisfies this proposition
bool Proposition::evaluate(const State& state) const {
    int propValue = state.getPropositionValue(name);
    switch (op) {
        case Operator::EQUAL:
            return propValue == value;
        case Operator::GREATER_OR_EQUAL:
            return propValue >= value;
        case Operator::LESS_OR_EQUAL:
            return propValue <= value;
        case Operator::GREATER:
            return propValue > value;
        case Operator::LESS:
            return propValue < value;
    }
    throw std::runtime_error("Unknown operator");
}
