#include "client_handler.hpp"
#include <boost/thread.hpp>

int main()
{
    client_manager mgr;
    boost::thread th(&client_manager::send_command, &mgr);
    th.detach();
    mgr.manage();
}