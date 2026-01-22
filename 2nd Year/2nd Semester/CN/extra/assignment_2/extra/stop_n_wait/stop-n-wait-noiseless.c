#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct {
	char msg[MAX_LEN];
	int ack;
	int seq;
} frame;

frame *buffer;
int ack = 0, seq = 0;

char* event = "Request";

void WaitForEvent(char *ev) {
	while (strcmp(event, ev)!=0) {};
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

void SendFrame(frame* f) {
	void Receiver();
	buffer = f;
	if (f->ack==0) Receiver();
}

char* ExtractData(frame *f) {
        return f->msg;
}

void Receiver() {
	frame* ReceiveFrame();
	frame *tmp = ReceiveFrame();
	if (tmp->ack==0) {
		WaitForEvent("Arrival_Data");
		char *op = ExtractData(tmp);
        	printf("Message extracted: %s", op);
    	   	printf("Packet number %d\n\n", tmp->seq);	
		event = "Arrival_ACK";
		frame *ACK = MakeFrame(tmp->msg, 1, tmp->seq);
		SendFrame(ACK);
		//event = "Arrival_ACK";
	}
	else {
		event = "Request";
	}
	free(tmp);
}

frame* ReceiveFrame() {
	frame *tmp = buffer;
	buffer = NULL;
	//char *op = ExtractData(tmp);
	//printf("Message extracted: %s", op);
	//printf("Packet number %d\n\n", tmp->seq);
	return tmp;
}

void DeliverData() {
	WaitForEvent("Request");
		char msg[MAX_LEN];
		GetData(msg);
		frame* f = MakeFrame(msg, 0, seq++);
		event = "Arrival_Data";
		SendFrame(f);
	WaitForEvent("Arrival_ACK");
		f = ReceiveFrame();
		if (f->ack==1) {
			printf("Acknowledgement received for Packet number %d\n\n", f->seq);
			event = "Request";
		}
	free(f);
		
}

int main() {
	char res[MAX_LEN]; int n;
	printf("Enter number of packets: ");
	scanf("%d", &n);
	getchar();
	while (seq<n) {
		DeliverData();
	}
}
