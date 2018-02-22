/*
 * Tyler Filla
 * CS 4280
 * Project 1
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

#include "scanner.h"
#include "scanner_tester.h"

int main(int argc, char* argv[])
{
    // Read from standard input by default
    std::istream* input_ptr = &std::cin;
    std::string input_name = "out";

    // If the user provided arguments
    if (argc > 1)
    {
        // Get the basename from first user argument
        // Concatenate the *.sp18 file extension to build the file name
        input_name = argv[1];
        auto file_name = std::string(input_name) + ".sp18";

        // Try to open the given file
        // HACK: This will get cleaned up on termination
        input_ptr = new std::ifstream(file_name); // TODO: Binary input

        if (!input_ptr)
        {
            std::cerr << "error: could not open file " << file_name << "\n";
            return 1;
        }
    }

    // Construct character iterators on the input stream
    auto& input = *input_ptr;
    std::istreambuf_iterator<char> input_begin(input);
    std::istreambuf_iterator<char> input_end {};

    // Construct scanner object
    p1::scanner<decltype(input_begin)> scanner(input_begin, input_end);

    // Construct test harness on scanner
    p1::scanner_tester<decltype(input_begin)> tester(scanner);

    // Test the scanner
    tester.test_scanner();

    return 0;
}
