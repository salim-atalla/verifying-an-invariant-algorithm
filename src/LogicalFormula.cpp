#include "LogicalFormula.h"

// Constructor for a simple proposition formula
LogicalFormula::LogicalFormula(const std::shared_ptr<Proposition> &proposition)
    : proposition(proposition), op(LogicalOperator::AND), left(nullptr), right(nullptr) {}

// Constructor for unary NOT operation
LogicalFormula::LogicalFormula(LogicalOperator op, const std::shared_ptr<LogicalFormula> &operand)
    : proposition(nullptr), op(op), left(operand), right(nullptr) {}

// Constructor for binary operations (AND, OR)
LogicalFormula::LogicalFormula(LogicalOperator op, const std::shared_ptr<LogicalFormula> &left, const std::shared_ptr<LogicalFormula> &right)
    : proposition(nullptr), op(op), left(left), right(right) {}

// Evaluates the logical formula and returns the result
bool LogicalFormula::evaluate() const {
    if (proposition) {
        // Base case: return the truth value of the proposition
        return proposition->getValue();
    }
    
    // Handle logical operators
    switch (op) {
        case LogicalOperator::AND:
            return left->evaluate() && right->evaluate();
        case LogicalOperator::OR:
            return left->evaluate() || right->evaluate();
        case LogicalOperator::NOT:
            return !left->evaluate();
    }
    return false;  // Should not reach here
}
