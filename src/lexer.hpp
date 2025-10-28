// lexer.hpp

#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <unordered_map>
#include <iostream>
#include <cctype>

namespace fling
{
    namespace lexer
    {
        // Token-Typen
        enum TokenType
        {
            Number,
            Identifier,

            Let,

            Equals,
            OpenParen,
            CloseParen,
            BinaryOperator,

            Illegal,
            Eof, // Signal end of File
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
    } // namespace lexer
} // namespace fling
