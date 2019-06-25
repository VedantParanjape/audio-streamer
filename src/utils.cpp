#include "utils.hpp"

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

void file_transfer(const char* filename, std::shared_ptr<boost::asio::ip::tcp::socket> sock)
{
    boost::asio::streambuf buffer;
    std::ostream bufferstream(&buffer);

    bufferstream << filename << "\n";
    bufferstream << filesize(filename) << "\n";
    bufferstream << picosha2::hash256_hex_string(file_content(filename));

    std::size_t headerbytes = boost::asio::write(*sock, buffer);
    std::size_t databytes = boost::asio::write(*sock, boost::asio::buffer(file_content(filename)));

    std::cout << "filename: " << filename << "\n"
              << "filesize: " << filesize(filename) << "\n"
              << "hash: " << picosha2::hash256_hex_string(file_content(filename)) << "\n";
    std::cout << "header bytes sent: " << headerbytes << "\n"
              << "data bytes sent: " << databytes << "\n";
}
