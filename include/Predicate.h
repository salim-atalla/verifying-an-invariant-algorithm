#ifndef PREDICATE_H
#define PREDICATE_H

#include <vector>
#include "Variable.h"
#include "Constant.h"

// Represents a predicate in first-order logic, holding variables and constants
class Predicate {
private:
    std::string name;  // Name of the predicate
    std::vector<Variable> variables;  // Variables associated with the predicate
    std::vector<Constant> constants;  // Constants associated with the predicate

public:
    // Constructor
    Predicate(const std::string &name);

    // Adds a variable to the predicate
    void addVariable(const Variable &variable);

    // Adds a constant to the predicate
    void addConstant(const Constant &constant);

    // Getter for the name of the predicate
    std::string getName() const;
};

#endif // PREDICATE_H
