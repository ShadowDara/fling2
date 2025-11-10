// parser.cpp

// Include necessary headers
#include "parser.hpp"

namespace fling {
    namespace parser {

        class Parser {

        private:
            // Array of tokens to parse
            std::vector<fling::lexer::Token> tokens;

            // Function to check if end of file is reached
            bool not_eof() {
                return this->tokens[0].type != fling::lexer::TokenType::Eof;
            }

            // Function to get the current token
            fling::lexer::Token at() {
                return this->tokens[0];
            }

            fling::ast::Stmt* parse_stmt() {
                // Skip to parse Expressions for now
                return this->parse_expr();
            }

            fling::ast::Expr* parse_expr() {
				return this->parse_primary_expr();
            }

            fling::ast::Expr* parse_primary_expr() {
                // Get the current token
                fling::lexer::Token tk = this->at().type;

                switch (tk.type) {
                case fling::lexer::TokenType::Identifier: {
                    return fling::lexer::TokenType::Identifier {
                        kind: "Identifier", symbol: this.at()
                    };
                default: {
                    return fling::ast::Stmt{};
                }
                }
                }
            }

        public:
            // Function to produce an AST from source code
            fling::ast::Program produceAST(const std::string& sourceCode) {
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

        } // namespace parser
        ;
    } // namespace fling
