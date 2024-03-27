#include "TCPserver.hpp"
#include "Client.hpp"

#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string ipAddress = "127.0.0.1";
	
	std::cout << "IP Address (default: 127.0.0.1): \n";
	std::getline(std::cin, ipAddress);

	int port = 8000;
	std::string input = "";
	std::cout << "Port (default 8000): \n";
	std::getline(std::cin, input);
	
	std::stringstream myStream(input);
	
	if (!(myStream >> port))
		port = 8000;

	std::cout << "You are connecting to port: " << port << " at address: " << ipAddress << std::endl;

	http::TCPserver server = http::TCPserver(ipAddress, port);
	http::Client client = http::Client();

	client.clientConnect(server.m_socket, server.hint);

	return 1;
}