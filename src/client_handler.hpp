#include "network_manager.hpp"
#include "thread_handler.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <curses.h>

class client_manager{
    private:
      network_manager nm;
      thread_handler hndlr;
      std::vector<std::shared_ptr<boost::asio::ip::tcp::socket>> socketsV;
      //boost::thread th;

    public:
      client_manager();
      void manage();  
      //void send_command();
};