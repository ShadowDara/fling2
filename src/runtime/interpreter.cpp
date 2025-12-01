// interpreter.cpp

#include "interpreter.hpp"

// Function to evaluate Source Code
fling::runtime::RuntimeVal evaluate(fling::ast::Stmt* astNode) {
    fling::runtime::RuntimeVal result;

    switch (astNode->kind) {
        case fling::ast::NodeType::NumericLiteral: {
            auto num = static_cast<fling::ast::NumericLiteral*>(astNode);
            result.type = fling::runtime::ValueType::Number;
            result.numberValue = num->value;
            return result;
        }
    }

    result.type = fling::runtime::ValueType::Null;
    return result;
}
