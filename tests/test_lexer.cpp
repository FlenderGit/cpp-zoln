#include "lexer_file.hpp"
#include "token.hpp"

int main() {

    LexerFile lexer("tests/test_lexer.cpp");
    while (true)
    {
        Token token = lexer.get_token();
        if (token == Token::T_EOF)
            break;
        std::cout << token << std::endl;
    }

    return 0;
}