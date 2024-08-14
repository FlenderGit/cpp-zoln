#pragma once

#include <fstream>

#include "../macro.hpp"
#include "lexer_base.hpp"

class LexerFile: public LexerBase
{
    public:
        LexerFile(const std::string &filename);
        ~LexerFile();

    private:
        std::ifstream file;

        char get_next_char() override;
};
