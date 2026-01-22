#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1024

void err(const char * ex) {
	perror(ex);
	exit(1);
}

int main() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd<0) err("Error creating socket!\n");
	
	printf("Successfully created socket\n");
	
	char serv_ip[INET_ADDRSTRLEN];
	unsigned short port;

	printf("Enter IP address: ");
	scanf("%s", serv_ip);
	
	printf("Enter port number: ");
	scanf("%hu", &port);

	struct sockaddr_in serv_addr = {
		.sin_family = AF_INET,
		.sin_port = htons(port),
		.sin_addr = inet_addr(serv_ip)
	}, cli_addr;
	
	bzero(&cli_addr, sizeof(cli_addr));
	
	int res = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if (res<0) err("Error bnding to given port\n");

	printf("Successfully bound to given port!\n");

	listen(sockfd, 1);
		
	socklen_t cli_len = sizeof(cli_addr);
	int connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
	if (connfd>=0) printf("Connected to client from port %hu\n", ntohs(cli_addr.sin_port));
	else return EXIT_FAILURE;
	
	while (1) {
		char rec[MAX_SIZE];
		bzero(rec, MAX_SIZE);
		int read_b = read(connfd, rec, MAX_SIZE);
		if (read_b <= 0) break;
		printf("Peer: %s", rec);
		
		char buf[MAX_SIZE];
		printf("Enter message: ");
		fgets(buf, MAX_SIZE, stdin);
		write(connfd, buf, strlen(buf));
	}
	
	printf("Closing connection...\n");
	return EXIT_SUCCESS;
}
