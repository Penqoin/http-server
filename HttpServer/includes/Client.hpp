#ifndef HTTP_CLIENT_WINDOWS
#define HTTP_CLIENT_WINDOWS

#define BUFFER_SIZE 4096

#include <WinSock2.h>
#include <WS2tcpip.h>

#include <string>
#include <iostream>

namespace http
{
	class Client
	{
	public:
		Client();
		~Client();

		void clientConnect(SOCKET _socket, sockaddr_in hint);

	private:
		void successLog(const std::string& message)
		{
			std::cout << message << std::endl;
			std::cout << std::string(message.size(), '-') << std::endl;
		}
		void errorLog(const std::string& message)
		{
			std::cout << message << std::endl;
		}
	};

}

#endif