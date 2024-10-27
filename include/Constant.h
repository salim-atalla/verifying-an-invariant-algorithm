#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>

// Represents a constant in first-order logic
class Constant {
private:
    std::string value;  // Value of the constant

public:
    // Constructor
    Constant(const std::string &value);

    // Getter for the value of the constant
    std::string getValue() const;
};

#endif // CONSTANT_H
