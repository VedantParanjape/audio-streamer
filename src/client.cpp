#include "network_manager.hpp"
#include <iostream>
typedef std::shared_ptr<ip::tcp::socket> sock;

int main()
{
    network_manage nm;
    char txt[15];
    sock sc = nm.client_init("127.0.0.1", 3434);
    
    sc->read_some(boost::asio::buffer(txt, 15));

    sc->close();
}