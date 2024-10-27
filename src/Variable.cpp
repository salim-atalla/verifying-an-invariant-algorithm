#include "Variable.h"

// Constructor for Variable
Variable::Variable(const std::string &name) : name(name) {}

// Returns the name of the variable
std::string Variable::getName() const {
    return name;
}
