#include "network_manager.hpp"
#include "thread_handler.hpp"
#include "utils.hpp"
#include <iostream>

class client_manager{
    private:
      network_manager nm;
      thread_handler hndlr;
 
    public:
      client_manager();
      void manage();  
};