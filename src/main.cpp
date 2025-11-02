#include "cli.h"
#include "polaroidify.h"
#include <cstdlib> // std::exit

int main(int argc, const char* argv[])
{
    CLI cli = CLI();

    if(!cli.parse(argc, argv))
    {
        return EXIT_FAILURE;
    }

    Polaroidify polaroidify = Polaroidify();
    std::size_t error = polaroidify.load(cli.file_path_input.c_str());

    if(error)
    {
        return EXIT_FAILURE;
    }

    polaroidify.add_border();

    error = polaroidify.save(cli.file_path_output.c_str());

    if(error)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
