#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <vector>

class thread_handler{
    private:
      std::vector<std::shared_ptr<boost::thread>> handle;

    public:
      void start_handle(void (*client_handle_func)(const char* ,std::shared_ptr<boost::asio::ip::tcp::socket>), const char* name ,std::shared_ptr<boost::asio::ip::tcp::socket> sk); 
      //void stop_handle();
};    
