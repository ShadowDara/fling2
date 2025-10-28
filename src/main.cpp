// main.cpp

#include "lexer.hpp"
#include "parser.hpp"
#include "ast.hpp"

#include <iostream>
#include <string>
#include <cassert> // Für assert()

using namespace fling;
using namespace fling::ast;
using namespace fling::lexer;
using namespace fling::parser;

    // Hilfsfunktion zum Testen von Tokens
    void assertToken(const lexer::Token& token, const std::string& expectedValue, lexer::TokenType expectedType) {
        if (token.type != expectedType || token.value != expectedValue) {
            std::cerr << "Token mismatch: got " << token.value << ", expected " << expectedValue << std::endl;
            std::exit(1);
        }
    }

    void runTests()
    {
        {
            std::vector<Token> tokens = tokenize("let y = 100 + 23");
			assert(tokens.size() == 7); // 6 Tokens + Eof
            assertToken(tokens[0], "let", TokenType::Let);
            assertToken(tokens[5], "23", TokenType::Number);
        }

        {
            std::vector<Token> tokens = tokenize("foo = (5 + 3)");
			assert(tokens.size() == 8); // 7 Tokens + Eof
            assertToken(tokens[0], "foo", TokenType::Identifier);
            assertToken(tokens[1], "=", TokenType::Equals);
            assertToken(tokens[2], "(", TokenType::OpenParen);
        }

        std::cout << "Tests 1\n";
    }

    int main()
    {
        std::cout << "Running Fling Tests...\n"
            << std::endl;

        std::vector<Token> tokens = tokenize("let x = 45");

        // Erwartet: 5 Tokens -> 4 + Eof Token at the end of the file
        assert(tokens.size() == 5 && "Expected 5 tokens");

        // Einzelne Tokens überprüfen
        assertToken(tokens[0], "let", TokenType::Let);
        assertToken(tokens[1], "x", TokenType::Identifier);
        assertToken(tokens[2], "=", TokenType::Equals);
        assertToken(tokens[3], "45", TokenType::Number);

        std::cout << "tests passed" << std::endl;

        runTests();

        std::string testthis = "let x = 90 * 90";
        std::cout << testthis << std::endl;
        tokenize(testthis);

		std::cout << "\nAll tests passed!\n" << std::endl;

        return 0;
    }
