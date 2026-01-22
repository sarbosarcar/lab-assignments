#include <iostream>
#include <cstring>

using namespace std;

extern "C" {
    void WaitForEvent() {
        cout << "Waiting for message to send..." << endl;
    }

    char* GetData() {
        static char data[256];
        cout << "Enter message to send: ";
        cin.getline(data, 256);
        return data;
    }

    char* MakeFrame(const char* data) {
        static char frame[256];
        strcpy(frame, "HEADER:");
        strcat(frame, data);
        cout << "Frame made: " << frame << endl;
        return frame;
    }

    void SendFrame(const char* frame) {
        cout << "Sent: " << frame << endl;
    }

    void SenderMain() {
        while (true) {
            WaitForEvent();
            char* data = GetData();
            if (strcmp(data, "exit") == 0) {
                break;
            }
            char* frame = MakeFrame(data);
            SendFrame(frame);
        }
    }
}

