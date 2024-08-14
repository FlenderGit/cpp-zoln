#include "lexer_base.hpp"

#include <string>

LexerBase::LexerBase()
{
    this->current_char = ' ';
    this->line_position = 0;
}

Token LexerBase::get_token()
{
    this->skip_whitespace();

    // Identifier 
    if (isalpha(this->current_char) || this->current_char == '_')
        return this->handle_identifier();

    // Number
    if (isdigit(this->current_char) || this->current_char == '.')
        return this->handle_number();

    switch (this->current_char)
    {
    case '#':
        while (this->current_char != '\n' && this->current_char != EOF)
            this->current_char = get_next_char();
        break;
    }

    // EOF
    if (this->current_char == EOF)
        return T_EOF;

    // Error
    return T_ERROR;
}

void LexerBase::skip_whitespace()
{
    while (isspace(this->current_char))
        this->current_char = get_next_char();
}

Token LexerBase::handle_identifier()
{
    this->identifier_string = this->current_char;
    this->current_char = get_next_char();

    while (isalnum(this->current_char) || this->current_char == '_')
    {
        this->identifier_string += this->current_char;
        this->current_char = get_next_char();
    }

    DEBUG_PRINT(fprintf(stderr, "IDENTIFIER : %s\n", this->identifier_string.c_str()));
    return T_IDENTIFIER;
}

Token LexerBase::handle_number()
{
    std::string number_string;
    bool is_float = false;

    while (isdigit(this->current_char) || this->current_char == '.')
    {
        if (this->current_char == '.')
            is_float = true;

        number_string += this->current_char;
        this->current_char = get_next_char();
    }

    if (is_float)
    {
        this->number_value = std::stod(number_string);
        return T_NUMBER;
    }

    this->number_value = std::stoi(number_string);
    return T_NUMBER;
}
