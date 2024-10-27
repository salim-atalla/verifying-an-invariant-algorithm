#include "Predicate.h"

// Constructor for Predicate
Predicate::Predicate(const std::string &name) : name(name) {}

// Adds a variable to the predicate
void Predicate::addVariable(const Variable &variable) {
    variables.push_back(variable);
}

// Adds a constant to the predicate
void Predicate::addConstant(const Constant &constant) {
    constants.push_back(constant);
}

// Returns the name of the predicate
std::string Predicate::getName() const {
    return name;
}
