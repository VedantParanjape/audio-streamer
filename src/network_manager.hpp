#include <boost/asio.hpp>

using namespace boost::asio;

class network_manage{
    private:
      io_service service;
      ip::tcp::endpoint ep;
      ip::tcp::acceptor acc;
      typedef std::shared_ptr<ip::tcp::socket> sock;
      bool isServer = false;

    public:
      network_manage();
      sock client_init(std::string ip, int port);
      int server_init(std::string, int port);
      sock accept_client();
      ~network_manage();
};