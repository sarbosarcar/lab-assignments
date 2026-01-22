#include "protocol.h"
#include "crc.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define WINDOW_SIZE 4
#define CHUNK_SIZE 8
#define MAX_FRAMES 100
#define MAX_SEQ_NUMBER 7

int seq_counter = 0;

void MakeFrame(Frame *f, char *data, int seq, int ack_seq, int include_ack) {
    f->seq = seq;
    f->ack = include_ack;
    f->nack = 0;
    if (data) strncpy(f->data, data, strlen(data));
    f->crc = crc_16((unsigned char *)f->data, strlen(f->data));
    if (include_ack) {
        f->ack = 1;
        f->seq = ack_seq;
    }
}

void CorruptFrame(Frame *f) {
    int pos;
    pos = rand() % strlen(f->data);
    f->data[pos] ^= (1 << (rand() % 8));
}

int BuildFrames(char *input, Frame frames[], int *frame_count) {
    int len, idx, pos;
    Frame f;
    len = strlen(input);
    idx = 0;
    pos = 0;
    while (pos < len) {
        bzero(&f, sizeof(f));
        strncpy(f.data, input + pos, CHUNK_SIZE);
        MakeFrame(&f, f.data, seq_counter, 0, 0);
        frames[idx++] = f;
        seq_counter = (seq_counter + 1) % (MAX_SEQ_NUMBER + 1);
        pos += CHUNK_SIZE;
    }
    *frame_count = idx;
    return 0;
}

int main() {
    int sockfd, prob, total, base, r;
    struct sockaddr_in addr, from;
    socklen_t len;
    char ip[INET_ADDRSTRLEN];
    unsigned short port;
    char input[1024];
    Frame frames[MAX_FRAMES];
    Frame recv;
    int acked[MAX_FRAMES];
    int i;

    srand(time(0));
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    GetAddress(ip);
    GetPort(&port);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    printf("Enter corruption probability (%%): ");
    scanf("%d", &prob);
    getchar();

    while (1) {
        bzero(input, sizeof(input));
        printf("Enter message: ");
        fgets(input, sizeof(input), stdin);
        if (strlen(input) <= 1) continue;

        BuildFrames(input, frames, &total);
        for (i = 0; i < MAX_FRAMES; i++) acked[i] = 0;
        base = 0;

        while (base < total) {
            for (i = base; i < total && i < base + WINDOW_SIZE; i++) {
                if (!acked[i]) {
                    Frame temp = frames[i];
                    if (rand() % 100 < prob) {
                        CorruptFrame(&temp);
                        printf("Corrupted frame seq %d\n", temp.seq);
                    } else {
                        printf("Sent frame seq %d\n", temp.seq);
                    }
                    sendto(sockfd, &temp, sizeof(temp), 0, (struct sockaddr *)&addr, sizeof(addr));
                }
            }

            SocketTime(sockfd, 6);
            len = sizeof(from);
            r = recvfrom(sockfd, &recv, sizeof(recv), 0, (struct sockaddr *)&from, &len);

            if (r > 0 && recv.ack) {
                printf("ACK received: seq %d, data: %s\n", recv.seq, recv.data);
                for (i = base; i < total; i++) {
                    if (frames[i].seq == recv.seq) {
                        acked[i] = 1;
                        break;
                    }
                }
                while (acked[base]) base++;
            } else {
                printf("Timeout — resending window\n");
                for (i = base; i < total && i < base + WINDOW_SIZE; i++) {
                    if (!acked[i]) {
                        Frame temp = frames[i];
                        if (rand() % 100 < prob) {
                            CorruptFrame(&temp);
                            printf("Corrupted timeout resend seq %d\n", temp.seq);
                        } else {
                            printf("Timeout resend seq %d\n", temp.seq);
                        }
                        sendto(sockfd, &temp, sizeof(Frame), 0, (struct sockaddr *)&addr, sizeof(addr));
                    }
                }
            }
        }
    }

    close(sockfd);
    return 0;
}
