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
        socketsV.push_back(sck);
        hndlr.start_handle(file_transfer, "florida.mp3", sck);
    }
}


void client_manager::send_command()
{
    char command[5];
	std::cin.ignore();
	 
    while(1)
	{
        std::cout << "1\n";
		 if(getchar())
		{
            std::cout << "2\n";
			std::cin.getline(command,5);
            std::cerr << command << "\n";
        }
		
		if(getchar())
		{
            std::cout << "play command givem !!";
			for(int i=0; i<socketsV.size(); i++)
            {
               socketsV[i]->write_some(buffer("play\n\n"));
            }
            break;
		}
    }
}