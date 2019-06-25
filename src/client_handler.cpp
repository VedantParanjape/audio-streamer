#include "client_handler.hpp"

client_manager::client_manager()
{
    nm.server_init("127.0.0.1", 9292);
    std::cout << "server initialised at 127.0.0.1:9292 \n";
}

void client_manager::manage()
{
    for(;;)
    {
        std::shared_ptr<boost::asio::ip::tcp::socket> sck = nm.accept_client();
        hndlr.start_handle(file_transfer, "florida.mp3", sck);
    }
}