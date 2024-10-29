#ifndef PROPOSITION_H
#define PROPOSITION_H

#include <string>
#include "State.h"


enum class Operator { EQUAL, GREATER_EQUAL, LESS_EQUAL, GREATER, LESS };


// Represents a logical proposition with a name and a truth value
class Proposition {
private:
    std::string name;
    int value;
    Operator op;

public:
    // Constructor
    Proposition(const std::string &name, int value, Operator op = Operator::EQUAL);

    // Getter for the name of the proposition
    std::string getName() const;

    // Getter for the truth value of the proposition
    int getValue() const;

    // Setter for the truth value of the proposition
    void setValue(int value);

    // Evaluates if the state satisfies this proposition
    bool evaluate(const State& state) const;
};

#endif // PROPOSITION_H
