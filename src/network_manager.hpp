#include <boost/asio.hpp>

using namespace boost::asio;

class network_manager{
    private:
      io_service service;
      ip::tcp::endpoint ep;
      bool isServer = false;

    public:
      network_manager();
      std::shared_ptr<ip::tcp::socket> client_init(std::string ip, int port);
      int server_init(std::string, int port);
      std::shared_ptr<ip::tcp::socket> accept_client();
      ~network_manager();
};