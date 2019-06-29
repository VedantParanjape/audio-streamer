#include "client_handler.hpp"
#include <boost/thread.hpp>

int main(int argc, char **argv)
{
    if(argc <= 1)
    {
        std::cout << "usage: ./server [filename] \n";
        std::_Exit(EXIT_FAILURE);
    }

    client_manager mgr;
    boost::thread th(&client_manager::send_command, &mgr);
    th.detach();
    mgr.manage(argv[1]);
}