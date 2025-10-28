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

        public:
            // Generate an AST from source code
            fling::ast::Program produceAST(const std::string& sourceCode);
        };

    } // namespace parser
} // namespace fling
