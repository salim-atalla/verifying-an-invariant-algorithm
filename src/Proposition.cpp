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
