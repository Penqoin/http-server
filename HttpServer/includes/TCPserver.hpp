#ifndef HTTP_TCPSERVER_WINDOWS
#define HTTP_TCPSERVER_WIDNOWS

#define BUFFER_SIZE 4096

#include <WinSock2.h>
#include <WS2tcpip.h>

#include <errors.h>
#include <string>
#include <iostream>


namespace http
{

	class TCPserver
	{
	public:
		SOCKET m_socket;
		sockaddr_in hint;

		TCPserver(std::string ipAddress, int port, WORD version = MAKEWORD(2, 2));
		~TCPserver();

	private:
		WSADATA wsData;
		WORD version;
		
		std::string ipAddress;
		int port;

		bool startServer();

		/*
			ERROR HANDELING
		*/

		void printERROR(const std::string& _message)
		{
			std::cerr << "ERROR: " + _message << std::endl;
		}

		void cleanup();
	};

} // namespace http

#endif