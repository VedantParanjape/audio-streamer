#include "network_manager.hpp"

using namespace boost::asio;

network_manager::network_manager(){

}

std::shared_ptr<ip::tcp::socket> network_manager::client_init(std::string ip, int port)
{
    //// add error checking 
    //// make sure only one of the following gets's called
    ep = ip::tcp::endpoint(ip::address::from_string(ip), port);
    std::shared_ptr<ip::tcp::socket> sckt(new ip::tcp::socket(service));
    sckt->connect(ep);

    return sckt;
}

int network_manager::server_init(std::string ip, int port)
{
    isServer = true;
    ep = ip::tcp::endpoint(ip::tcp::v4(), port);
}

std::shared_ptr<ip::tcp::socket> network_manager::accept_client()
{
    // do this only if init as a server
    std::shared_ptr<ip::tcp::socket> sckt(new ip::tcp::socket(service));
    ip::tcp::acceptor(service, ep).accept(*sckt);
    
    std::cout << "client connected\n";
    return sckt;
}

network_manager::~network_manager()
{
    service.stop();
}
