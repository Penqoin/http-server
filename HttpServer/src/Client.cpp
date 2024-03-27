#include "Client.hpp"

namespace http
{
	Client::Client()
	{

	}
	Client::~Client()
	{

	}

	void Client::clientConnect(SOCKET _socket, sockaddr_in hint)
	{
		int connection = connect(_socket, (sockaddr*)&hint, sizeof(hint));
		if (connection == SOCKET_ERROR)
		{
			std::string temp = std::to_string(WSAGetLastError());
			errorLog(temp);
			closesocket(_socket);
			WSACleanup();

			return;
		}

		char buf[BUFFER_SIZE];
		std::string userInput;

		do
		{
			std::cout << "> ";
			std::getline(std::cin, userInput);

			if (userInput.size() > 0)
			{
				int sendResult = send(_socket, userInput.c_str(), userInput.size() + 1, 0);
				if (sendResult != SOCKET_ERROR)
				{
					ZeroMemory(buf, BUFFER_SIZE);
					
					int recieved = recv(_socket, buf, BUFFER_SIZE, 0);
					if (recieved > 0)
						std::cout << "SERVER> " << std::string(buf, 0, recieved) << std::endl;
				}
			}
		} while (userInput != "exit");

		closesocket(_socket);
		WSACleanup();
	}
}