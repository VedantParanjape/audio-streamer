#include "network_manager.hpp"
#include <iostream>

int main()
{
    network_manager nm;
    char txt[15];
    std::shared_ptr<ip::tcp::socket> sc = nm.client_init("127.0.0.1", 3434);

    sc->read_some(boost::asio::buffer(txt, 15));
    std::cout << txt;
    sc->close();
}