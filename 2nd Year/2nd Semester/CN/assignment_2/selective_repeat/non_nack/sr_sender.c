#include "protocol.h"
#include "crc.h"
#include <time.h>
#include <sys/time.h>

#define WINDOW_SIZE 4
#define CHUNK_SIZE 8
#define MAX_FRAMES 100
#define MAX_SEQ_NUMBER 7

int seq_counter = 0;

void MakeFrame(Frame *f, char *data, int seq) {
    f->seq = seq;
    f->ack = 0;
    f->nack = 0;
    strncpy(f->data, data, strlen(data));
    f->crc = crc_16((unsigned char *)f->data, strlen(f->data));
}

void CorruptFrame(Frame *f) {
    int pos;
    pos = rand() % strlen(f->data);
    f->data[pos] ^= (1 << (rand() % 8));
}

int BuildFrames(char *input, Frame frames[], int *count) {
    int len, idx, pos;
    Frame f;

    len = strlen(input);
    idx = 0;
    pos = 0;

    while (pos < len) {
        bzero(&f, sizeof(f));
        strncpy(f.data, input + pos, CHUNK_SIZE);
        MakeFrame(&f, f.data, seq_counter);
        frames[idx++] = f;
        seq_counter = (seq_counter + 1) % (MAX_SEQ_NUMBER + 1);
        pos += CHUNK_SIZE;
    }
    *count = idx;
    return 0;
}

int main() {
    int sockfd, prob, total, base;
    struct sockaddr_in addr, from;
    socklen_t len;
    char ip[INET_ADDRSTRLEN];
    unsigned short port;
    char input[1024];

    Frame frames[MAX_FRAMES], ack;
    int acked[MAX_FRAMES];
    int sent[MAX_FRAMES];
    struct timeval sent_time[MAX_FRAMES];
    struct timeval now;

    int i, r;

    srand(time(0));

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) exit(1);

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

        for (i = 0; i < MAX_FRAMES; i++) {
            acked[i] = 0;
            sent[i] = 0;
        }

        base = 0;

        while (base < total) {
            gettimeofday(&now, NULL);

            for (i = base; i < base + WINDOW_SIZE && i < total; i++) {
                long elapsed;
                int send_now = 0;

                if (acked[i]) continue;

                if (!sent[i]) {
                    send_now = 1;
                } else {
                    elapsed = now.tv_sec - sent_time[i].tv_sec;
                    if (elapsed >= 2) send_now = 1;
                }

                if (send_now) {
                    Frame f = frames[i];
                    if (rand() % 100 < prob) {
                        CorruptFrame(&f);
                        printf("Corrupted frame seq %d\n", f.seq);
                    } else {
                        printf("Sent frame seq %d\n", f.seq);
                    }
                    sendto(sockfd, &f, sizeof(f), 0, (struct sockaddr *)&addr, sizeof(addr));
                    gettimeofday(&sent_time[i], NULL);
                    sent[i] = 1;
                }
            }

            SocketTime(sockfd, 1);
            len = sizeof(from);
            r = recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&from, &len);

            if (r > 0 && ack.ack) {
                printf("ACK for seq %d\n", ack.seq);
                for (i = base; i < total; i++) {
                    if (frames[i].seq == ack.seq) {
                        acked[i] = 1;
                        break;
                    }
                }
                while (acked[base]) base++;
            }
        }
    }

    close(sockfd);
    return 0;
}
