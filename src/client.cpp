#include "network_manager.hpp"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "boost/lexical_cast.hpp"
#include "../third-party/PicoSHA2/picosha2.h"
int main(int argc, char **argv)
{
    if(argc < 2)
    {
       std::cout << "usage: ./client [server IP] [server PORT]\n";
       std::_Exit(EXIT_FAILURE);
    }
    network_manager nm;
    boost::asio::streambuf bufheader;
    std::string filename, filesize, hash;
    std::shared_ptr<ip::tcp::socket> sc = nm.client_init(argv[1], boost::lexical_cast<int>(argv[2]));
    
    std::size_t headerbytes = boost::asio::read_until(*sc, bufheader, "\n\n");
    std::istream bufstream(&bufheader);

    bufstream >> filename;
    bufstream >> filesize;
    bufstream >> hash;

    bufheader.consume(headerbytes);

    std::size_t databytes = read(*sc, bufheader, transfer_exactly(boost::lexical_cast<int>(filesize)));

/////////////////////////////////////////////////////////////////////////////
    char file_n[] = "test.mp3";                                           ///
    std::ofstream fileout(file_n, std::ios_base::binary);                 ///
                                                                          ///
    boost::asio::streambuf::const_buffers_type bufs = bufheader.data();   ///
    std::string str(boost::asio::buffers_begin(bufs),                     ///
    boost::asio::buffers_begin(bufs) + bufheader.size());                 ///
                                                                          ///
    fileout.write(str.c_str(), str.size());                               ///
    fileout.close();                                                      ///
/////////////////////////////////////////////////////////////////////////////

    std::cout << "data from header: \n";
    std::cout << filename << "\n"
              << filesize << "\n"
              << hash << "\n";

    std::cout << "data from client side: \n"
              << "header bytes: " << headerbytes << "\n"
              << "data bytes: " << databytes << "\n"
              << "hash: " << picosha2::hash256_hex_string(str) << "\n";
     
    bufheader.consume(databytes);
    
    char command[10];
    headerbytes = boost::asio::read_until(*sc, bufheader, "\n\n");
    std::string cmnd = command;
    
    std::cout << command << "\n";
    if(hash == picosha2::hash256_hex_string(str) && headerbytes > 0)
    {
        std::cout << "playing audio....\n";
        system("python ../src/play_audio.py");
    }
}