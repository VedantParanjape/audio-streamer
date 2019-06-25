#include "thread_handler.hpp"

void thread_handler::start_handle(void (*client_handle_func)(const char* ,std::shared_ptr<boost::asio::ip::tcp::socket>), const char* name ,std::shared_ptr<boost::asio::ip::tcp::socket> sk)
{
    std::shared_ptr<boost::thread> th(new boost::thread(boost::bind(client_handle_func, name, sk)));
    handle.push_back(th);
    th->detach();
}

/* /void thread_handler::stop_handle()
{
    for(int i=0; i< handle.size(); i++)
    {
        handle[i]->~thread();
    }

    handle->erase();
}*/