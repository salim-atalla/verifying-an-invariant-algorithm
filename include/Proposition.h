#ifndef PROPOSITION_H
#define PROPOSITION_H

#include <string>
#include "State.h"



// Enum class representing different comparison operators used for evaluating propositions.
enum class Operator { EQUAL, GREATER_OR_EQUAL, LESS_OR_EQUAL, GREATER, LESS };



// Represents a logical proposition with a name and a truth value
class Proposition {
private:
    std::string name;
    int value;
    Operator op;

public:
    // Constructor
    Proposition(const std::string &name, int value, Operator op = Operator::EQUAL);

    // Getters for the name, value of the proposition
    std::string getName() const;
    int getValue() const;

    // Setter for the truth value of the proposition
    void setValue(int value);

    // Evaluates if the state satisfies this proposition
    bool evaluate(const State& state) const;
};

#endif // PROPOSITION_H
