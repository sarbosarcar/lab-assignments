#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crc.h"

#define MAX_LEN 1024

typedef struct {
	char msg[MAX_LEN];
	int ack;
	int seq;
	unsigned short crc;
} frame;

frame *buffer;
int ack = 0, seq = 0;

char* event = "Request";

void WaitForEvent(char *ev) {
	while (strcmp(event, ev)!=0) {printf("%s", event);}
}

void GetData(char* msg) {
	printf("Enter message to send: ");
	fgets(msg, MAX_LEN, stdin);
}

frame* MakeFrame(char* msg, int ack, int seq) {
	frame *tmp = (frame*) malloc(sizeof(frame));
	strcpy(tmp->msg, msg);
	tmp->ack = ack;
	tmp->seq = seq;
	return tmp;
}

int SendFrame(frame* f) {
	buffer = f;
	return 1;
}

char* ExtractData(frame *f) {
        return f->msg;
}

frame* ReceiveFrame() {
	WaitForEvent("Arrival");
	frame *tmp = buffer;
	buffer = NULL;
	char *op = ExtractData(tmp);
	printf("Message extracted: %s", op);
	printf("Packet number %d\n\n", tmp->seq);
	free(tmp);
	event = "Request";
}

void DeliverData() {
	WaitForEvent("Request");
		char msg[MAX_LEN];
		GetData(msg);
		frame* f = MakeFrame(msg, ack, seq++);
		SendFrame(f);
		event = "Arrival";
}

int main() {
	char res[MAX_LEN]; int n;
	printf("Enter number of frames to send: ");
	scanf("%d", &n);
	getchar();
	while (seq<n) {
		DeliverData();
		ReceiveFrame();
	}
}
