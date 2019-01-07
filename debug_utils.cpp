#include "debug_utils.h"

void debug_print(std::string debug_str)
{
    #ifdef DEBUG_MODE
    std::cout << debug_str << std::endl;
    #endif
}