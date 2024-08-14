#pragma once

#include <iostream>

#define ERROR_CRASH(msg) { std::cerr << msg << std::endl; exit(1); }

// DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(msg) { std::cerr << msg << std::endl; }
#else
#define DEBUG_PRINT(msg)
#endif