#include "lexer.hpp"
#include "ast.hpp"
#include <iostream>
#include <string>
#include <cassert> // Für assert()

// Hilfsfunktion zum Testen von Tokens
void assertToken(const Token& token, const std::string& expectedValue, TokenType expectedType) {
    assert(token.value == expectedValue && "Token value does not match");
    assert(token.type == expectedType && "Token type does not match");
}

void runTests() {
    {
        std::vector<Token> tokens = tokenize("let y = 100 + 23");
        assert(tokens.size() == 6);
        assertToken(tokens[0], "let", TokenType::Let);
        assertToken(tokens[5], "23", TokenType::Number);
    }

    {
        std::vector<Token> tokens = tokenize("foo = (5 + 3)");
        assert(tokens.size() == 7);
        assertToken(tokens[0], "foo", TokenType::Identifier);
        assertToken(tokens[1], "=", TokenType::Equals);
        assertToken(tokens[2], "(", TokenType::OpenParen);
    }

    std::cout << "Tests 1\n";
}


int main() {
    std::cout << "Running Fling Tests...\n" << std::endl;

    std::vector<Token> tokens = tokenize("let x = 45");

    // Erwartet: 4 Tokens
    assert(tokens.size() == 4 && "Expected 4 tokens");

    // Einzelne Tokens überprüfen
    assertToken(tokens[0], "let", TokenType::Let);
    assertToken(tokens[1], "x", TokenType::Identifier);
    assertToken(tokens[2], "=", TokenType::Equals);
    assertToken(tokens[3], "45", TokenType::Number);

    std::cout << "tests passed" << std::endl;

    runTests();

    std::string testthis = "let x = 99 * 99";
    std::cout << testthis << std::endl;
    tokenize(testthis);

    return 0;
}
