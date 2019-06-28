#include "client_handler.hpp"
#include <boost/thread.hpp>

int main()
{
    client_manager mgr;
    boost::thread th(mgr.send_command);
    th.detach();
    mgr.manage();
}