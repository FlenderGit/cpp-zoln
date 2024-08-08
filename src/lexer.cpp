#include <string>
#include "lexer.hpp"
#include "token.hpp"

Token ZolnLexer::get_token()
{
    this->skip_whitespace();

    // Identifier 
    if (isalpha(this->current_char))
        return this->handle_identifier();

    // Number
    if (isdigit(this->current_char) || this->current_char == '.')
        return this->handle_number();

    // EOF
    if (this->current_char == EOF)
        return T_EOF;

    // Error
    this->error_string = "Unknown token : " + this->current_char;
    return T_ERROR;
}

void ZolnLexer::skip_whitespace()
{
    while (isspace(this->current_char))
        this->current_char = getchar();
}

Token ZolnLexer::handle_identifier()
{
    this->identifier_string = this->current_char;
    this->current_char = getchar();

    while (isalnum(this->current_char))
    {
        this->identifier_string += this->current_char;
        this->current_char = getchar();
    }

    return T_IDENTIFIER;
}

Token ZolnLexer::handle_number()
{
    std::string number_string;
    bool is_float = false;

    while (isdigit(this->current_char) || this->current_char == '.')
    {
        if (this->current_char == '.')
            is_float = true;

        number_string += this->current_char;
        this->current_char = getchar();
    }

    if (is_float)
    {
        this->number_value = std::stod(number_string);
        return T_NUMBER;
    }

    this->number_value = std::stoi(number_string);
    return T_NUMBER;
}

char ZolnLexer::get_next_char()
{
    return ' ';
}