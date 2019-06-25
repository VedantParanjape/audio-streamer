#include <iostream>
#include "utils.hpp"
#include "../third-party/PicoSHA2/picosha2.h"

int main()
{
    char filename[50];

    std::cin >> filename;
    std::cout << "filename: " << filename << "\n";
    std::cout << "filesize: " << filesize(filename) << "\n";
    std::cout << "hash: " << picosha2::hash256_hex_string(file_content(filename)) << "\n";
}