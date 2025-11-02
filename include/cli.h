#ifndef __CLI_H
#define __CLI_H

#include "cxxopts.hpp"
#include <cstdlib> // std::exit
#include <iostream> // std::cerr, std::endl
#include <string> // std::string

class CLI
{
public:
    CLI();
    bool parse(int argc, const char* argv[]);
    std::string to_string();

    std::string file_path_input;
    std::string file_path_output;
};

#endif
