#include <boost/thread.hpp>
#include <vector>

class thread_handler{
    private:
      std::vector<std::shared_ptr<boost::thread>> handle;

    public:
      void start_handle(void (*client_handle_func)(int ,int), int a, int b); 
      //void stop_handle();
};    
