#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>

#define DATA "Hello world of socket"

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in server;
	struct hostent *hp; 
	char buff[1024];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("scoket failed");
		exit(1);
	}

	server.sin_family = AF_INET;

	hp = gethostbyname(argv[1]);
	if (hp == 0) {
		perror("gethostname failed");
		close(sock);
		exit(1);
	}

	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(5000);

	if(connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
		perror("connect failed");
		close(sock);
		exit(1);
	}
	
	if (send(sock, DATA, sizeof(DATA), 0) < 0) {
		perror("send failed");
		close(sock);
		exit(1);
	}
	printf("sent %s\n", DATA);
	close(sock);
	return 0;
}
