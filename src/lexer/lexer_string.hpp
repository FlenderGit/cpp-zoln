#pragma once

#include "../macro.hpp"
#include "lexer_base.hpp"

class LexerString: public LexerBase
{
    public:
        LexerString(const std::string &program);
        ~LexerString();

    private:
        std::string program;
        int position;

        char get_next_char() override;
};
