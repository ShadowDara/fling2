#pragma once

#include <vector>
#include <string>

namespace fling
{
    namespace ast
    {

        // Enum für Knotentypen
        enum class NodeType
        {
            Program,
            NumericLiteral,
            Identifier,
            BinaryExpr,
            // CallExpr,
            // UnaryExpr,
            // FunctionDeclaration
        };

        // Basisstruktur (Statement)
        struct Stmt
        {
            NodeType kind;
        };

        // Program
        struct Program
        {
            NodeType kind = NodeType::Program; // TypeTag
            std::vector<Stmt *> body;          // Liste von Statements
        };

        // Ausdruck
        struct Expr
        {
            NodeType kind;
        };

        // Binary Expression
        struct BinaryExpr
        {
            NodeType kind = NodeType::BinaryExpr;
            Expr *left;
            Expr *right;

            // String-Konvertierung (optional)
            operator std::string() const
            {
                return "BinaryExpr";
            }
        };

        // Identifier
        struct Identifier
        {
            NodeType kind = NodeType::Identifier;
            std::string symbol;
        };

        // Numerisches Literal
        struct NumericLiteral
        {
            NodeType kind = NodeType::NumericLiteral;
            int number;
        };

    } // namespace ast
} // namespace fling
