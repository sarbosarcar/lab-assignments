#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 25000
#define MAX_LEN 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[MAX_LEN];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }
	
    printf("Server is ready to receive messages...\n");

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(1);
    }
    
    client_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Client accept failed");
        exit(1);
    }
    while (1) {
        memset(buffer, 0, MAX_LEN);
        int len = read(client_fd, buffer, MAX_LEN);
        if (len <= 0) {
            break;
        }
        printf("Client: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            write(client_fd, "Goodbye!", 8);
            break;
        } else {
	    char temp[MAX_LEN];	
	    printf("Enter response for client: ");
	    fgets(temp, MAX_LEN, stdin);
	    //char tmp[MAX_LEN];
	    //snprintf(tmp, MAX_LEN, "Server: %s", temp);
            write(client_fd, temp, MAX_LEN);
        }
    }

    close(client_fd);
    close(server_fd);
    return 0;
}

