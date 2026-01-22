#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 25000
#define MAX_LEN 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    while (1) {
        printf("You: ");
        fgets(buffer, MAX_LEN, stdin);
        write(sockfd, buffer, strlen(buffer));

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        memset(buffer, 0, MAX_LEN);
        int len = read(sockfd, buffer, MAX_LEN);
        if (len <= 0) {
            break;
        }
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}

