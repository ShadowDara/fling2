// parser.cpp

#include "parser.hpp"

namespace fling {
    namespace parser {
		// Function to produce an AST from source code
        fling::ast::Program Parser::produceAST(const std::string& sourceCode) {
            fling::ast::Program program;
            program.kind = fling::ast::NodeType::Program;
            program.body = {}; // empty body

            // später: tokenize + parse logic hier einfügen

            return program;
        }

    } // namespace parser
} // namespace fling
