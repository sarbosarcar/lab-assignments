#include <iostream>
#include <cstring>

using namespace std;

extern "C" {
    void WaitForEvent() {
        cout << "Waiting for message to receive..." << endl;
    }

    char* ReceiveFrame() {
        static char receivedFrame[256];
        cout << "Enter received message (simulate sender input): ";
        cin.getline(receivedFrame, 256);
        return receivedFrame;
    }

    char* ExtractData(const char* frame) {
        static char data[256];
        strcpy(data, frame + strlen("HEADER:"));
        return data;
    }

    void DeliverData(const char* data) {
        cout << "Receiver received: " << data << endl;
        cout << "Receiver's response: ";
        char response[256];
        cin.getline(response, 256);
        cout << "Sent by receiver: " << response << endl;
    }

    void ReceiverMain() {
        while (true) {
            WaitForEvent();
            char* frame = ReceiveFrame();
            if (strcmp(frame, "exit") == 0) {
                break;
            }
            char* data = ExtractData(frame);
            DeliverData(data);
        }
    }
}

