#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

// Represents a variable in first-order logic
class Variable {
private:
    std::string name;  // Name of the variable

public:
    // Constructor
    Variable(const std::string &name);

    // Getter for the name of the variable
    std::string getName() const;
};

#endif // VARIABLE_H
