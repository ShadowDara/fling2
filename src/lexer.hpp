// lexer.hpp
#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <unordered_map>
#include <iostream>
#include <cctype>

// use namespace lexer
// {
    // Token-Typen
    enum TokenType
    {
        Number,
        Identifier,
        Equals,
        OpenParen,
        CloseParen,
        BinaryOperator,
        Let,
        Illegal
    };

    // Token-Struktur
    struct Token
    {
        std::string value;
        TokenType type;
    };

    // Funktions-Deklarationen
    std::string tokenTypeToString(TokenType type);
    std::ostream &operator<<(std::ostream &os, const Token &token);

    bool isAlpha(const std::string &src);
    bool isAlpha(char c);
    bool isInt(const std::string &str);
    bool isInt(char c);
    bool isSkippable(char c);

    Token token(const std::string &value, TokenType type);
    std::vector<Token> tokenize(const std::string &input);

    extern std::unordered_map<std::string, TokenType> KEYWORDS;
// }
