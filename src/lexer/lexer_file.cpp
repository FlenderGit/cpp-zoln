#include "lexer_file.hpp"

LexerFile::LexerFile(const std::string &filename) : LexerBase()
{
    std::ifstream file(filename);
    if (!file.good())
        ERROR_CRASH("File not found: " + filename);
    this->file = std::move(file);
}

LexerFile::~LexerFile()
{
    this->file.close();
}

inline char LexerFile::get_next_char()
{
    int c = this->file.get();

    if (c == EOF) {
        DEBUG_PRINT(fprintf(stderr, "EOF\n"));
        return EOF;
    }
    char ca = static_cast<char>(c);
    return ca;
}