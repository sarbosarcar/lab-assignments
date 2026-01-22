#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_LEN 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[MAX_LEN];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    printf("Server is ready to receive messages...\n");

    while (1) {
        memset(buffer, 0, MAX_LEN);
        client_len = sizeof(client_addr);

        int len = recvfrom(sockfd, buffer, MAX_LEN, 0, (struct sockaddr *)&client_addr, &client_len);
        if (len < 0) {
            perror("Recvfrom failed");
            continue;
        }

        printf("Client: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            sendto(sockfd, "Goodbye!", 8, 0, (struct sockaddr *)&client_addr, client_len);
            break;
        }
	char temp[MAX_LEN];
	char tmp[MAX_LEN];
	printf("Enter response for client: ");
	fgets(temp, MAX_LEN, stdin);
	//snprintf(tmp, MAX_LEN, "Server: %s", temp);
        sendto(sockfd, temp, MAX_LEN, 0, (struct sockaddr *)&client_addr, client_len);
    }

    close(sockfd);
    return 0;
}

