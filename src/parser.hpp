// parser.hpp

#pragma once

#include <string>
#include <vector>
#include "lexer.hpp"
#include "ast.hpp"

namespace fling {
    namespace parser {

        class Parser {
        private:
            // Array of tokens to parse
            std::vector<fling::lexer::Token> tokens;

			// Function to check if end of file is reached
            bool not_eof();

			// Function to get the current token
            fling::lexer::Token at();

			// Function to parse a statement
            fling::ast::Stmt* parse_stmt();

			// Function to parse an expression
            fling::ast::Expr* parse_expr();

			// Function to parse a primary expression
            fling::ast::Expr* parse_primary_expr();

        public:
            // Generate an AST from source code
            fling::ast::Program produceAST(const std::string& sourceCode);
        };

    } // namespace parser
} // namespace fling
