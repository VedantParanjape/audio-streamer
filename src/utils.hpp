#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ostream>
#include "../third-party/PicoSHA2/picosha2.h"
#include <boost/asio.hpp>

std::ifstream::pos_type filesize(const char* filename);

std::string file_content(const char* filename);

void file_transfer(const char* filename, std::shared_ptr<boost::asio::ip::tcp::socket> sock);

