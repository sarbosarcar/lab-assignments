#include <iostream>
#include <cstring>
#include "../common/protocol.h"

using namespace std;

void WaitForEvent() {
    cout << "Waiting for event to send data..." << endl;
}

char* GetData() {
    static char data[] = "Hello, Receiver!";
    cout << "Data to send: " << data << endl;
    return data;
}

Frame MakeFrame(char* data) {
    Frame frame;
    frame.header = strlen(data);
    frame.data = data;
    frame.dataLength = strlen(data);
    cout << "Frame created with header length: " << frame.header << endl;
    return frame;
}

void SendFrame(Frame* frame) {
    cout << "Sending frame with data: " << frame->data << endl;
}

extern "C" __attribute__((visibility("default"))) void SendData() {
    WaitForEvent();
    char* data = GetData();
    Frame frame = MakeFrame(data);
    SendFrame(&frame);
}
