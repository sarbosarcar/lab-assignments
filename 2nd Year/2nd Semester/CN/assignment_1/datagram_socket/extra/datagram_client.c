#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_LEN 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LEN];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAX_LEN, stdin);

        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        memset(buffer, 0, MAX_LEN);
        int len = recvfrom(sockfd, buffer, MAX_LEN, 0, NULL, NULL);
        if (len < 0) {
            perror("Recvfrom failed");
            continue;
        }

        printf("Server: %s\n", buffer);

        if (strncmp(buffer, "Goodbye!", 8) == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}

