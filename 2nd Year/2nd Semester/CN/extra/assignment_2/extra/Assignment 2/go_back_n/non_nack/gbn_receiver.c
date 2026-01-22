#include "protocol.h"
#include "crc.h"

void MakeFrame(Frame *f, char *buf, int seq, int ack) {
    f->seq = seq;
    f->ack = ack;
    if (!ack) strncpy(f->data, buf, strlen(buf));
    f->crc = crc_16((unsigned char *)buf, strlen(buf));
}

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) perror("Socket creation failed!\n"), exit(1);

    char rec_ip[INET_ADDRSTRLEN];
    unsigned short port;
    GetAddress(rec_ip);
    GetPort(&port);

    struct sockaddr_in rec_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = inet_addr(rec_ip)
    }, cli_addr;

    bzero(&cli_addr, sizeof(cli_addr));

    if (bind(sockfd, (struct sockaddr *)&rec_addr, sizeof(rec_addr)) < 0)
        perror("Failed to bind to port!\n"), exit(1);

    printf("Receiver ready on port %hu\n", port);

    socklen_t cli_len = sizeof(cli_addr);

    int expected_seq = 0;

    while (1) {
        Frame f;
        int n = recvfrom(sockfd, &f, sizeof(f), 0, (struct sockaddr *)&cli_addr, &cli_len);

        if (n <= 0) {
            printf("Error reading frame!\n");
            continue;
        }

        unsigned short crc_c = crc_16((unsigned char *)f.data, strlen(f.data));

        if (crc_c == f.crc) {
            if (f.seq == expected_seq) {
                printf("Correct frame received! Seq: %d, Data: %s\n", f.seq, f.data);
                expected_seq++;
            } else {
                printf("Out of order frame received. Expected %d but got %d. Discarding.\n", expected_seq, f.seq);
            }
        } else {
            printf("CRC error in frame seq %d. Discarding.\n", f.seq);
        }

        // Always send ACK for last correctly received seq -1
        Frame ack = {.seq = expected_seq - 1, .ack = 1};
        sendto(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&cli_addr, cli_len);
        printf("Sent cumulative ACK for seq %d\n", expected_seq - 1);
    }

    close(sockfd);
    return 0;
}
