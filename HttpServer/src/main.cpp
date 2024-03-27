#include "TCPserver.hpp"
#include "Client.hpp"

int main()
{
	http::TCPserver server = http::TCPserver();
	http::Client client = http::Client();

	client.clientConnect(server.m_socket, server.hint);

	return 1;
}