// Server side C program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8081
int main(int argc, char const* argv[]){
	int server_fd, new_socket;
	ssize_t valread;
	struct sockaddr_in address;
	int opt = 1;
	socklen_t addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* hello = "Hello from server";

	//int sockfd = socket(domain, type, protocol) 
	//domain: integer, specifies communication domain. We use AF_ LOCAL as defined in the POSIX standard for communication between processes on the same host. For communicating between processes on different hosts connected by IPV4, we use AF_INET and AF_I NET 6 for processes connected by IPV6.
	//AF_INET is the Internet address family for IPv4. SOCK_STREAM is the socket type for TCP, the protocol that will be used to transport messages in the network.
	//type:SOCK_STREAM: TCP(reliable, connection-oriented) SOCK_DGRAM: UDP(unreliable, connectionless)
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
//20240416
	//int setsockopt(int sockfd, int level, int optname,  const void *optval, socklen_t optlen);
	//Using setsockopt helps in manipulating options for the socket referred by the file descriptor sockfd. This is completely optional, but it helps in reuse of address and port. Prevents error such as: “address already in use”.
	//See https://pubs.opengroup.org/onlinepubs/000095399/functions/setsockopt.html	
	//level is the protocol level for which the socket option is being set. SOL_SOCKET and IPPROTO_TCP are supported. All optname values beginning with “SO_” are for protocol level SOL_SOCKET and are interpreted by the general socket code. All optname values beginning with “TCP_” are for protocol level IPPROTO_TCP and are interpreted by the TCP/IP internal code.
	//SO_BINDTODEVICE : Bind this socket to a symbolic device name like eth0 instead of using bind() to bind it to an IP address. Type the command ifconfig under Unix to see the device names.
	//SO_REUSEADDR : Allows other sockets to bind() to this port, unless there is an active listening socket bound to the port already. This enables you to get around those "Address already in use" error messages when you try to restart your server after a crash.
	//SO_BROADCAST : Allows UDP datagram (SOCK_DGRAM) sockets to send and recieve packets sent to and from the broadcast address. Does nothing--NOTHING!!--to TCP stream sockets!
	//As for the parameter optval, it's usually a pointer to an int indicating the value in question. For booleans, zero is false, and non-zero is true. And that's an absolute fact, unless it's different on your system. If there is no parameter to be passed, optval can be NULL.
	//The final parameter, optlen, is filled out for you by getsockopt() and you have to specify it for getsockopt(), where it will probably be sizeof(int). Warning: on some systems (notably Sun and Windows), the option can be a char instead of an int, and is set to, for example, a character value of '1' instead of an int value of 1. Again, check your own man pages for more info with "man setsockopt" and "man 7 socket"! 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket
		= accept(server_fd, (struct sockaddr*)&address,
				&addrlen))
		< 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	valread = read(new_socket, buffer,
				1024 - 1); // subtract 1 for the null
							// terminator at the end
	printf("%s\n", buffer);
	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent\n");

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	close(server_fd);
	return 0;
}

