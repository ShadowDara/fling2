// ast.hpp

/**
 * Header file for the Abstract Syntax Tree for the Language
 */

#pragma once

#ifndef AST_HPP
#define AST_HPP

#include <string_view>
#include <vector>
#include <string>
#include <ostream>

namespace fling
{
    namespace ast
    {
        /**
         * Function to prodruce an Indent String
         *
         * @param int for the indent counter
         * @return std::string for indents
         */
        static std::string indentStr(int indent)
        {
            return std::string(indent, ' ');
        }

        /**
         * enum class for the NodeTypes for the Abstract Syntax Tree
         */
        enum class NodeType
        {
            Program,
            NumericLiteral,
            NullLiteral,
            Identifier,
            BinaryExpr,
            // CallExpr,
            // UnaryExpr,
            // FunctionDeclaration
        };

        /**
         * Statement a Basestructure for the abstract Syntax Tree
         *
         * @param Nodetype
         */
        struct Stmt
        {
            NodeType kind;

            // toString function
            virtual std::string toString(int indent = 0) const
            {
                return "<Stmt>";
            }

            virtual ~Stmt() = default;
        };

        // Program
        struct Program : Stmt
        {
            NodeType kind = NodeType::Program; // TypeTag
            std::vector<Stmt *> body;          // Liste von Statements

            // toString function
            std::string toString(int indent = 0) const override
            {
                std::string out = indentStr(indent) + "Program:\n";

                for (auto *stmt : body)
                {
                    out += stmt->toString(indent + 2);
                    // Add newline After each statement
                    out += "\n";
                }

                return out;
            }
        };

        // Ausdruck
        struct Expr : Stmt
        {
        };

        // Binary Expression
        struct BinaryExpr : Expr
        {
            NodeType kind = NodeType::BinaryExpr;
            Expr *left;
            Expr *right;
            std::string callculation_operator;

            // String-Konvertierung (optional)
            operator std::string() const
            {
                return "BinaryExpr";
            }

            // toString function
            std::string toString(int indent = 0) const override
            {
                std::string out = indentStr(indent) + "BinaryExpr:\n";
                out += indentStr(indent + 2) + "Left:\n";
                out += left->toString(indent + 4) + "\n";
                out += indentStr(indent + 2) + "Right:\n";
                out += right->toString(indent + 4) + "\n";
                out += indentStr(indent + 2) + "Binary Operator:\n";
                out += indentStr(indent + 4) + callculation_operator;
                return out;
            }
        };

        // Identifier
        struct Identifier : Expr
        {
            NodeType kind = NodeType::Identifier;
            std::string symbol;

            // toString function
            std::string toString(int indent = 0) const override
            {
                return indentStr(indent) + "Identifier(" + symbol + ")";
            }
        };

        // Numerisches Literal
        struct NumericLiteral : Expr
        {
            NodeType kind = NodeType::NumericLiteral;
            int value;

            // toString Function
            std::string toString(int indent = 0) const override
            {
                return indentStr(indent) + "NumericLiteral(" + std::to_string(value) + ")";
            }
        };

        // Null Literal
        struct NullLiteral : Expr
        {
            NodeType kind = NodeType::NullLiteral;
            std::string value = "null";

            // toString Function
            std::string toString(int indent = 0) const override
            {
                return indentStr(indent) + "NullLiteral";
            }
        };

        // for toString
        inline std::ostream &operator<<(std::ostream &os, const fling::ast::Stmt &stmt)
        {
            os << stmt.toString();
            return os;
        }

        // for toString
        inline std::ostream &operator<<(std::ostream &os, const fling::ast::Program &program)
        {
            os << program.toString();
            return os;
        }

    } // namespace ast
} // namespace fling

#endif // AST_HPP
