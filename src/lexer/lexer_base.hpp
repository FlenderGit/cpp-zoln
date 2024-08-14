#pragma once

#include <string>
#include "../token.hpp"
#include "../macro.hpp"

class LexerBase
{

public:

    std::string identifier_string;
    double number_value;

    LexerBase();
    virtual ~LexerBase() = default;

    Token get_token();    

protected:

    char current_char;
    int line_position;

    char get_current_char();
    int get_line_position();

    virtual char get_next_char() = 0;

    void skip_whitespace();
    Token handle_identifier();
    Token handle_number();
};