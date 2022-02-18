#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netint/in.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* variables */
	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;

	/* create Scoket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0) {
		perror("Failed to create Scoket");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = 5000;

	/* Call bind */
	if (bind(sock, &server, sizeof(server))) {
		perror("bind failed");
		exit(1);
	}
	
	/* Listen */

	listen(sock, 5);

	/* Accept */
	do {
		mysock = accept(sock, (struct sockaddr *) 0, 0);
		if (mysock == 1)
			perror("accept failed");
		else
			memset(buf, 0, sizeof(buff));
			if ((rval = recv(mysock, buff, sizeof(buf), 0)) < 0)
				perror("reading stream message error")
			else if (rval == 0)
				printf("Ending Connection\n");
			else
				printf("done\n";
			printf("Got message (rval = %d) \n", rval);
			close(mysock);
			

	} while (1);
	return 0;
}
