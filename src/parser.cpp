// parser.cpp

#include "parser.hpp"

namespace fling {
    namespace parser {
		// Function to check if end of file is reached
        bool not_eof() {
			return this->tokens[0].type != fling::lexer::TokenType::Eof;   
        }

		// Function to get the current token
        fling::lexer::Token at() {
			return this->tokens[0];
        }

		// Function to produce an AST from source code
        fling::ast::Program Parser::produceAST(const std::string& sourceCode) {
			this->tokens = fling::lexer::tokenize(sourceCode);

            fling::ast::Program program;
            program.kind = fling::ast::NodeType::Program;
            program.body = {}; // empty body

            // später: tokenize + parse logic hier einfügen
            
			// Parse until end of file
            while (!this->not_eof()) {
				program.body.push_back(this->parse_stmt());
            }

            return program;
        }

        fling::ast::Stmt* parse_stmt() {
			// Skip to parse Expressions for now
			return this->parse_expr();
        }

        fling::ast::Expr* parse_expr() {}

        fling::ast::Expr* parse_primary_expr() {
			// Get the current token
			fling::lexer::Token tk = this->at().type;

            switch (tk.type) {
                case fling::lexer::TokenType::Identifier {
                    break;
                }
            }
        }

    } // namespace parser
} // namespace fling
