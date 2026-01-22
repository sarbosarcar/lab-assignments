#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#define MAX_SIZE 4096

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;
    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main() {
    int sock;
    struct sockaddr_in dest;
    struct iphdr *iph;
    struct icmphdr *icmph;
    char packet[MAX_SIZE];
    char send_msg[1024];
    char ip_addr[INET_ADDRSTRLEN];
    unsigned short port;

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    printf("Enter destination IP address: ");
    scanf("%s", ip_addr);
    
    printf("Enter destination port number: ");
    scanf("%hu", port);

    char src_ip[INET_ADDRSTRLEN];
    printf("Enter source IP address: ");
    scanf("%s", src_ip);

    dest.sin_family = AF_INET;
    dest.sin_port = port;
    dest.sin_addr.s_addr = inet_addr(ip_addr);

    while (1) {
        printf("You: ");
        fgets(send_msg, sizeof(send_msg), stdin);
        send_msg[strcspn(send_msg, "\n")] = 0;

        // Clear the packet buffer
        memset(packet, 0, MAX_SIZE);

        // Construct the IP header
        iph = (struct iphdr *)packet;
        iph->ihl = 5;
        iph->version = 4;
        iph->tos = 0;
        iph->tot_len = sizeof(struct iphdr) + sizeof(struct icmphdr) + strlen(send_msg);  // Add payload length to total length
        iph->id = htonl(54321);
        iph->frag_off = 0;
        iph->ttl = 255;
        iph->protocol = IPPROTO_ICMP;
        iph->check = 0;  // Set to 0 before calculating checksum
        iph->saddr = inet_addr(src_ip);  // Source IP address
        iph->daddr = dest.sin_addr.s_addr;  // Destination IP address
        iph->check = checksum((unsigned short *)packet, iph->tot_len);  // Calculate IP checksum

        // Construct the ICMP header
        icmph = (struct icmphdr *)(packet + sizeof(struct iphdr));
        icmph->type = ICMP_ECHO;
        icmph->code = 0;
        icmph->checksum = 0;  // Set to 0 before calculating checksum
        icmph->un.echo.id = getpid();
        icmph->un.echo.sequence = 1;
        icmph->checksum = checksum((unsigned short *)icmph, sizeof(struct icmphdr));  // Calculate ICMP checksum

        // Copy the payload (message) into the packet after the ICMP header
        memcpy(packet + sizeof(struct iphdr) + sizeof(struct icmphdr), send_msg, strlen(send_msg));

        // Send the complete packet (IP header + ICMP header + payload)
        //sendto(sock, packet, iph->tot_len, 0, (struct sockaddr *)&dest, sizeof(dest));
        
        ssize_t sent_bytes = sendto(sock, packet, iph->tot_len, 0, (struct sockaddr *)&dest, sizeof(dest));

    // Check if sendto was successful
    if (sent_bytes < 0) {
        perror("Failed to send packet");
    } else {
        printf("Successfully sent %zd bytes\n", sent_bytes);
    }
    }

    close(sock);
    return 0;
}

