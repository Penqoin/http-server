#include "TCPserver.hpp"

namespace http
{
	TCPserver::TCPserver(std::string ipAddress, WORD version, int port)
		: ipAddress(ipAddress), version(version), port(port)
	{
		if (startServer())
		{
			std::cout << "success" <<  std::endl;
		}
	}

	TCPserver::~TCPserver()
	{
		cleanup();
	}
	
	bool TCPserver::startServer()
	{
		if (WSAStartup(version, &wsData) != 0)
		{
			printERROR("FAILED TO INIT WSA");
			return 0;
		}

		m_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (m_socket == INVALID_SOCKET)
		{
			printERROR("FAILED TO INIT SOCKET");
			WSACleanup();
			return 0;
		}

		// bind ip addr and port to socket
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

		return 1;
	}

	void TCPserver::cleanup()
	{
		closesocket(m_socket);
		WSACleanup();
	}

} // namespace http