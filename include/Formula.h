#ifndef FORMULA_H
#define FORMULA_H

#include <memory>
#include "Predicate.h"

// Represents a formula in first-order logic, which is built upon predicates
class Formula {
private:
    std::shared_ptr<Predicate> predicate;  // Predicate associated with the formula

public:
    // Constructor
    Formula(const std::shared_ptr<Predicate> &predicate);

    // Getter for the predicate associated with the formula
    std::shared_ptr<Predicate> getPredicate() const;
};

#endif // FORMULA_H
