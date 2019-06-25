#include "network_manager.hpp"
#include <iostream>

int main()
{
    network_manager nm;

    nm.server_init("127.0.0.1", 3434);
    std::shared_ptr<boost::asio::ip::tcp::socket> sc = nm.accept_client();

    std::cout << sc->write_some(boost::asio::buffer("hello world !!", 14));

    sc->close();
}