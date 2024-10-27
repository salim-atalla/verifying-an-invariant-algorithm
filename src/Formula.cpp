#include "Formula.h"

// Constructor for Formula
Formula::Formula(const std::shared_ptr<Predicate> &predicate) : predicate(predicate) {}

// Returns the predicate associated with the formula
std::shared_ptr<Predicate> Formula::getPredicate() const {
    return predicate;
}
