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
	};
	
	int connfd = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	
	while (1) {		
		char buf[MAX_SIZE];
		printf("Enter message: ");
		fgets(buf, MAX_SIZE, stdin);
		write(sockfd, buf, strlen(buf));
		
		char rec[MAX_SIZE];
		bzero(rec, MAX_SIZE);
		read(sockfd, rec, MAX_SIZE);
		printf("Peer: %s", rec);	
	}
	
	printf("Closing connection...\n");
	return EXIT_SUCCESS;
}			
