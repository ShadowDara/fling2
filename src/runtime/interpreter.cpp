// interpreter.cpp

#include "interpreter.hpp"

using namespace std;

namespace fling
{
    namespace runtime
    {
        // Function to evaluate a Program
        runtime::RuntimeVal *evaluate_program(ast::Program *program) {}

        // Function to evaluate a Binary Expression
        runtime::RuntimeVal *evaluate_binary_expr(ast::BinaryExpr *binop) {}

        // Function to evaluate Source Code
        runtime::RuntimeVal *evaluate(ast::Stmt *astNode)
        {
            switch (astNode->kind)
            {

            // Number Value
            case ast::NodeType::NumericLiteral:
            {
                auto numNode = static_cast<ast::NumericLiteral *>(astNode);
                return new runtime::NumberVal(numNode->value); // korrekt: Pointer
            }

            // Null Value
            case ast::NodeType::NullLiteral:
            {
                return new runtime::NullVal(); // korrekt: Pointer
            }

            // Binary Expression
            case ast::NodeType::BinaryExpr:
            {
                return evaluate_binary_expr(static_cast<ast::BinaryExpr *>(astNode));
            }

            // Program Node
            case ast::NodeType::Program:
            {
            }

            // Error Fallback
            default:
            {
                cout << "Unknown AST Node Type in evaluate()" << endl;
                core::Exit(1);
            }
            }
        }
    }
}
