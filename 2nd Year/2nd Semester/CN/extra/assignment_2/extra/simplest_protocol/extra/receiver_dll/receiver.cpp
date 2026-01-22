#include <iostream>
#include <cstring>
#include "../common/protocol.h"

void WaitForEvent() {
    std::cout << "Waiting for frame to receive..." << std::endl;
}

void ReceiveFrame(Frame* frame) {
    std::cout << "Receiving frame with data: " << frame->data << std::endl;
}

char* ExtractData(Frame* frame) {
    return frame->data;
}

void DeliverData(char* data) {
    std::cout << "Delivered data: " << data << std::endl;
}

extern "C" __attribute__((visibility("default"))) void ReceiveData() {
    WaitForEvent();
    Frame frame;
    ReceiveFrame(&frame);
    char* data = ExtractData(&frame);
    DeliverData(data);
}
