#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

std::string file_content(const char* filename)
{
    std::ifstream filein(filename, std::ios_base::binary);
    std::stringstream sstr;
    sstr << filein.rdbuf();
    return sstr.str();
}

