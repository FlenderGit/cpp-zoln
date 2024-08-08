#pragma once

#include <string>
#include "token.hpp"

class ZolnLexer
{

public:

    // TD : static fields
    std::string identifier_string;
    double number_value;
    std::string error_string;

    char current_char;
    std::string line;
    int line_pos;

    Token get_token();    

private:
    void skip_whitespace();
    char get_next_char();
    Token handle_identifier();
    Token handle_number();
};