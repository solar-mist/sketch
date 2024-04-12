// Copyright 2024 solar-mist

#include "lexer/Token.h"

#include <sstream>
#include <format>

namespace lexing
{
    Token::Token(const TokenType tokenType, const std::string& text)
        :mTokenType(tokenType), mText(text)
    {
    }

    Token::Token(const TokenType tokenType, std::string&& text)
        :mTokenType(tokenType), mText(std::move(text))
    {
    }

    Token::Token(const TokenType tokenType)
        :mTokenType(tokenType), mText("")
    {
    }

    TokenType Token::getTokenType() const
    {
        return mTokenType;
    }

    const std::string& Token::getText() const
    {
        return mText;
    }

    static inline const char* TypeToString(TokenType tokenType)
    {
        switch(tokenType)
        {
            case TokenType::Error:
                return "Error";

            case TokenType::Identifier:
                return "Identifier";

            case TokenType::LeftParen:
                return "LeftParen";
            case TokenType::RightParen:
                return "RightParen";
            case TokenType::LeftBracket:
                return "LeftBracket";
            case TokenType::RightBracket:
                return "RightBracket";

            case TokenType::IntegerLiteral:
                return "IntegerLiteral";
            
            case TokenType::Semicolon:
                return "Semicolon";
            case TokenType::Asperand:
                return "Asperand";
            case TokenType::RightArrow:
                return "RightArrow";

            case TokenType::Type:
                return "Type";
            case TokenType::FuncKeyword:
                return "Func";
            case TokenType::ReturnKeyword:
                return "Return";
        }
    }

    std::string Token::toString() const
    {
        return std::format("{}({})", TypeToString(mTokenType), mText);
    }

    bool Token::operator==(Token other)
    {
        return ((mText == other.mText) && (mTokenType == other.mTokenType));
    }
}