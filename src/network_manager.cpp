#include "network_manager.hpp"

using namespace boost::asio;

std::shared_ptr<ip::tcp::socket> network_manage::client_init(std::string ip, int port)
{
    //// add error checking 
    //// make sure only one of the following gets's called
    ep = ip::tcp::endpoint(ip::address::from_string(ip), port);
    std::shared_ptr<ip::tcp::socket> sckt(new ip::tcp::socket(service));
    sckt->connect(ep);

    return sckt;
}

int network_manage::server_init(std::string ip, int port)
{
    isServer = true;
    ep = ip::tcp::endpoint(ip::tcp::v4(), port);
    acc = ip::tcp::acceptor(service, ep);
}

std::shared_ptr<ip::tcp::socket> network_manage::accept_client()
{
    // do this only if init as a server
    std::shared_ptr<ip::tcp::socket> sckt(new ip::tcp::socket(service));
    acc.accept(*sckt);

    return sckt;
}

network_manage::~network_manage()
{
    service.stop();
}
