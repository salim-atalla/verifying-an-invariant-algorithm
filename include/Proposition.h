#ifndef PROPOSITION_H
#define PROPOSITION_H

#include <string>

// Represents a logical proposition with a name and a truth value
class Proposition {
private:
    std::string name;    // Name of the proposition
    bool value;          // Truth value of the proposition

public:
    // Constructor
    Proposition(const std::string &name, bool value);

    // Getter for the name of the proposition
    std::string getName() const;

    // Getter for the truth value of the proposition
    bool getValue() const;

    // Setter for the truth value of the proposition
    void setValue(bool value);
};

#endif // PROPOSITION_H
