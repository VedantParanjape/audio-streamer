#include <boost/asio.hpp>

using namespace boost::asio;

class network_manage{
    private:
      io_service service;
      ip::tcp::endpoint ep;
      ip::tcp::acceptor acc;
      bool isServer = false;

    public:
      network_manage();
      std::shared_ptr<ip::tcp::socket> client_init(std::string ip, int port);
      int server_init(std::string, int port);
      std::shared_ptr<ip::tcp::socket> accept_client();
      ~network_manage();
};