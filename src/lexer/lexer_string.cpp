#include "lexer_string.hpp"

LexerString::LexerString(const std::string &program)
    : program(program), position(0)
{
    this->program += '\0';
}

LexerString::~LexerString() {}

char LexerString::get_next_char()
{
    return program[position++];
}