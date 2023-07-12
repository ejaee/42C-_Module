#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 9000

int main(int argc, char *argv[])
{
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;

	int n;
	char buffer[BUFSIZ];

	s_socket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_port = htons(PORT);

	if (bind(s_socket, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1) {
		printf("Can not Bind\n");
		return -1;
	}
	if (listen(s_socket, 5) == -1) {
		printf("listen Fail\n");
		return -1;
	}

	while (1) {
		len =sizeof(c_addr);
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len);
		while ((n))
	}

// 	const char *message = "\
// HTTP/1.1 200 OK\r\n\
// Server: Apache/2.2.14 (Win32)\r\n\
// Content-Length: 53\r\n\
// Content-Type: text/html\r\n\
// Connection: close\r\n\
// \n\
// <html>\n\
// <body>\n\
// <h1>Hello, World!</h1>\n\
// </body>\n\
// </html>\n";

// 	int connectSd, sd, maxSd, listenSd, maxClients = 30;
// 	fd_set readFds;

// 	while (1)
// 	{
// 		maxSd = getMaxfd(listenSd) + 1;
// 		FD_ZERO(&readFds);
// 		FD_SET(listenSd, &readFds);
// 		for (int i = 0; i < maxClients; i++)
// 			FD_SET(sd, &readFds);

// 		for (int i = 0; i < maxClients; i++)
// 			FD_SET(clientSockets[i], &readFds);

// 		connectSd = select(maxSd + 1, &readFds, NULL, NULL, NULL);
// 		if (connectSd < 0)
// 		{
// 			printf("select error\n");
// 			exit(-1);
// 		}
// 		printf("Waiting---\n");
// 		if (FD_ISSET(listenSd, &readFds))
// 		{
// 			connectSd = accept(listenSd, (struct sockaddr *)&sockAddr, (socklen_t *)&sockAddrLen);
// 			clientSockets[maxClients++] = connectSd;
// 		}
// 		for (int i = 0; i < maxClients; i++)
// 		{
// 			if (FD_ISSET(clientSockets[i], &readFds))
// 			{
// 				if ((n = read(clientSockets[i], buffer, sizeof(buffer))) != 0)
// 				{
// 					buffer[n] = '\n';
// 					printf("receive - [%s]\n", buffer);
// 					write(clientSockets[i], buffer, n);
// 					printf("receive - [%s]\n", buffer);
// 				}
// 				else
// 				{
// 					print("EOF\n");
// 					close(clientSockets[i]);
// 					if (i != maxClients - 1)
// 						clientSockets[i] = clientSockets[maxClients - 1];
// 					maxClients--;
// 					continue;
// 				}
// 			}
// 		}
// 	}
// }
// int getMaxfd(int n)
// {
// 	int max = n;
// 	for (int i = 0; i < maxClients; i++)
// 	{
// 		if (clientSockets[i] > max)
// 			max = clientSockets[i];
// 	}
// 	return max;
// }
// Port generateServer(int port) {

// 		if ((listenSd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
// 			exit(-1);

// 		int opt = 1;
// 		// set master socket to allow multiple connections,
// 		// this is just a good habit, it will work without this
// 		if (setsockopt(listenSd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
// 					   sizeof(opt)) < 0)
// 			exit(-1);

// 		// type of socket created
// 		sockAddr.sin_family = AF_INET;
// 		sockAddr.sin_addr.s_addr = INADDR_ANY;
// 		sockAddr.sin_port = htons(port);

// 		// bind the socket to localhost port
// 		if (bind(listenSd, (struct sockaddr *)&sockAddr, sizeof(sockAddr)) < 0)
// 			exit(-1);

// 		// try to specify maximum of 3 pending connections for the master socket
// 		if (listen(listenSd, 3) < 0)
// 			exit(-1);

// 		// accept the incoming connection
// 		sockAddrLen = sizeof(sockAddr);
}
