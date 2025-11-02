#include "cli.h"

CLI::CLI()
{
    file_path_input = "";
    file_path_output = "";
    return;
}

bool CLI::parse(int argc, const char* argv[])
{
    try
    {
        cxxopts::Options options("polaroidify", "CLI image processing tool");

        options.custom_help("-i <INPUT_FILE_PATH> -o <OUTPUT_FILE_PATH> [OPTIONS...]");
        options.set_width(80);
        options.set_tab_expansion();

        options.add_options()
            ("h,help", "Displays help")
            ("i,input", "Specifies the input png image file path", cxxopts::value<std::string>(), "<FILE_PATH>")
            ("o,output", "Specifies the file path the output png will be saved to", cxxopts::value<std::string>(), "<FILE_PATH>")
        ;

        cxxopts::ParseResult result = options.parse(argc, argv);

        if(result.count("help"))
        {
            std::cout << options.help() << std::endl;
            std::exit(EXIT_SUCCESS);
        }

        if(result.count("input"))
        {
            file_path_input = result["input"].as<std::string>();
        }
        else
        {
            std::cerr << "Error: No input image file path specified" << std::endl;
            return false;
        }

        if(result.count("output"))
        {
            file_path_output = result["output"].as<std::string>();
        }
        else
        {
            std::cerr << "Error: No output image file path specified" << std::endl;
            return false;
        }
    }
    catch (const cxxopts::exceptions::exception& e)
    {
        std::cerr << "Error parsing options: " << e.what() << std::endl;
        return false;
    }

    return true;
}

std::string CLI::to_string()
{
    std::string output = "";
    output += "file_path_input: " + file_path_input + "\n";
    output += "file_path_output: " + file_path_output + "\n";
    return output;
}
