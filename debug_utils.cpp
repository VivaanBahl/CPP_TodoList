#include "debug_utils.h"

void debug_print(std::string debug_str)
{

    std::string homedir = getenv("HOME");
    std::string debug_file = homedir + "/.todo/DEBUG.txt";
    
    std::ofstream debug_out(debug_file, std::ofstream::app);
    debug_out << "[";
    std::time_t timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string timestr = std::string(std::ctime(&timenow));
    timestr = timestr.substr(0, timestr.size() - 1);
    debug_out << timestr;
    debug_out << "] : ";
    debug_out << debug_str << std::endl;
}