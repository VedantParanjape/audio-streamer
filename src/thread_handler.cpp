#include "thread_handler.hpp"

void thread_handler::start_handle(void (*client_handle_func)(int, int), int a, int b)
{
    std::shared_ptr<boost::thread> th(new boost::thread(boost::bind(client_handle_func, a, b)));
    handle.push_back(th);
    th->detach();
}

/* /void thread_handler::stop_handle()
{
    for(int i=0; i< handle.size(); i++)
    {
        handle[i]->~thread();
    }
}*/