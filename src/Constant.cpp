#include "Constant.h"

// Constructor for Constant
Constant::Constant(const std::string &value) : value(value) {}

// Returns the value of the constant
std::string Constant::getValue() const {
    return value;
}
