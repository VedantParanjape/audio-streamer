#include "network_manager.hpp"
#include <iostream>
typedef std::shared_ptr<ip::tcp::socket> sock;

int main()
{
    network_manage nm;

    nm.server_init("127.0.0.1", 3434);
    sock sc = nm.accept_client();

    sc->write_some(boost::asio::buffer("hello world !!", 14));

    sc->close();
}