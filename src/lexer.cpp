// lexer.cpp

#include "lexer.hpp"

namespace fling
{
    namespace lexer
    {

        // Debug Printing
        std::string tokenTypeToString(TokenType type)
        {
            switch (type)
            {
            case Number:
                return "Number";
            case Identifier:
                return "Identifier";
            case Equals:
                return "Equals";
            case OpenParen:
                return "OpenParen";
            case CloseParen:
                return "CloseParen";
            case BinaryOperator:
                return "BinaryOperator";
            case Let:
                return "Let";
            default:
                return "Unknown";
            }
        }

        std::ostream &operator<<(std::ostream &os, const Token &token)
        {
            os << "Token(type=\"" << tokenTypeToString(token.type) << "\", value=\"" << token.value << "\")";
            return os;
        }

        // Check if string is alphabetic
        bool isAlpha(const std::string &src)
        {
            for (char c : src)
            {
                if (!std::isalpha(static_cast<unsigned char>(c)))
                {
                    return false;
                }
            }
            return true;
        }

        // Overload: Check if single char is alpha
        bool isAlpha(char c)
        {
            return std::isalpha(static_cast<unsigned char>(c));
        }

        // Check if string is integer
        bool isInt(const std::string &str)
        {
            if (str.empty())
                return false;
            for (char c : str)
            {
                if (!std::isdigit(static_cast<unsigned char>(c)))
                {
                    return false;
                }
            }
            return true;
        }

        bool isInt(char c)
        {
            return std::isdigit(static_cast<unsigned char>(c));
        }

        // Whitespace check
        bool isSkippable(char c)
        {
            return c == ' ' || c == '\n' || c == '\t';
        }

        // Token-Erzeuger
        Token token(const std::string &value, TokenType type)
        {
            return Token{value, type};
        }

        // Keywords
        std::unordered_map<std::string, TokenType> KEYWORDS = {
            {"let", TokenType::Let},
        };

        // Tokenizer
        std::vector<Token> tokenize(const std::string &sourceCode)
        {
            std::vector<Token> tokens;
            std::vector<char> src(sourceCode.begin(), sourceCode.end());

            for (size_t i = 0; i < src.size();)
            {
                char current = src[i];

                if (isSkippable(current))
                {
                    i++;
                    continue;
                }

                switch (current)
                {
                case '(':
                    tokens.push_back(token("(", TokenType::OpenParen));
                    i++;
                    break;
                case ')':
                    tokens.push_back(token(")", TokenType::CloseParen));
                    i++;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    tokens.push_back(token(std::string(1, current), TokenType::BinaryOperator));
                    i++;
                    break;
                case '=':
                    tokens.push_back(token("=", TokenType::Equals));
                    i++;
                    break;
                default:
                    // Zahl aufbauen
                    if (isInt(current))
                    {
                        std::string num;
                        while (i < src.size() && isInt(src[i]))
                        {
                            num += src[i];
                            i++;
                        }
                        tokens.push_back(token(num, TokenType::Number));
                    }
                    // Identifier aufbauen
                    else if (isAlpha(current))
                    {
                        std::string ident;
                        while (i < src.size() && isAlpha(src[i]))
                        {
                            ident += src[i];
                            i++;
                        }

                        if (KEYWORDS.find(ident) != KEYWORDS.end())
                        {
                            tokens.push_back(token(ident, KEYWORDS[ident]));
                        }
                        else
                        {
                            tokens.push_back(token(ident, TokenType::Identifier));
                        }
                    }
                    else
                    {
                        std::cout << "Unrecognized character in source: " << current << std::endl;
                        std::abort();
                    }

                    break;
                }
            }

            tokens.push_back(token("EndOfFile", TokenType::Eof));

            // Debug Output
            std::cout << "Debug Tokens:" << std::endl;
            for (const auto &tok : tokens)
            {
                std::cout << tok << std::endl;
            }

            return tokens;
        }

    } // namespace lexer
} // namespace fling
