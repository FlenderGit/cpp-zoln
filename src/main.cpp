#include <stdio.h>
#include "zoln.hpp"
#include "lexer/lexer_file.hpp"
#include "token.hpp"
#include <iostream>

int main() {

    LexerFile lexer("tests/program.zoln");
    while (true)
    {
        Token token = lexer.get_token();
        if (token == Token::T_EOF)
            break;
        std::cout << token << std::endl;
    }

    return 0;
}