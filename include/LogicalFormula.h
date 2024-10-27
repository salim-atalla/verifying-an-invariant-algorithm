#ifndef LOGICALFORMULA_H
#define LOGICALFORMULA_H

#include <memory>
#include "Proposition.h"

// Enum for logical operators
enum class LogicalOperator {
    AND,
    OR,
    NOT
};

// Represents a logical formula which can contain propositions or other formulas
class LogicalFormula {
private:
    std::shared_ptr<Proposition> proposition;  // Proposition if it's a base formula
    LogicalOperator op;                        // Logical operator (AND, OR, NOT)
    std::shared_ptr<LogicalFormula> left;      // Left operand for binary operations
    std::shared_ptr<LogicalFormula> right;     // Right operand for binary operations

public:
    // Constructor for a simple proposition
    LogicalFormula(const std::shared_ptr<Proposition> &proposition);

    // Constructor for unary NOT operation
    LogicalFormula(LogicalOperator op, const std::shared_ptr<LogicalFormula> &operand);

    // Constructor for binary operations (AND, OR)
    LogicalFormula(LogicalOperator op, const std::shared_ptr<LogicalFormula> &left, const std::shared_ptr<LogicalFormula> &right);

    // Evaluates the logical formula and returns the result
    bool evaluate() const;
};

#endif // LOGICALFORMULA_H
