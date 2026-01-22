#include <iostream>
#include <dlfcn.h>

typedef void (*WaitForEventFunc)();
typedef char* (*GetDataFunc)();
typedef char* (*MakeFrameFunc)(const char*);
typedef void (*SendFrameFunc)(const char*);
typedef char* (*ReceiveFrameFunc)();
typedef char* (*ExtractDataFunc)(const char*);
typedef void (*DeliverDataFunc)(const char*);
typedef void (*SenderMainFunc)();
typedef void (*ReceiverMainFunc)();

int main() {
    void* senderLib = dlopen("./sender.so", RTLD_LAZY);
    void* receiverLib = dlopen("./receiver.so", RTLD_LAZY);

    if (!senderLib || !receiverLib) {
        std::cerr << "Failed to load libraries!" << std::endl;
        return 1;
    }

    WaitForEventFunc WaitForEventSender = (WaitForEventFunc)dlsym(senderLib, "WaitForEvent");
    GetDataFunc GetData = (GetDataFunc)dlsym(senderLib, "GetData");
    MakeFrameFunc MakeFrame = (MakeFrameFunc)dlsym(senderLib, "MakeFrame");
    SendFrameFunc SendFrame = (SendFrameFunc)dlsym(senderLib, "SendFrame");

    WaitForEventFunc WaitForEventReceiver = (WaitForEventFunc)dlsym(receiverLib, "WaitForEvent");
    ReceiveFrameFunc ReceiveFrame = (ReceiveFrameFunc)dlsym(receiverLib, "ReceiveFrame");
    ExtractDataFunc ExtractData = (ExtractDataFunc)dlsym(receiverLib, "ExtractData");
    DeliverDataFunc DeliverData = (DeliverDataFunc)dlsym(receiverLib, "DeliverData");

    SenderMainFunc SenderMain = (SenderMainFunc)dlsym(senderLib, "SenderMain");
    ReceiverMainFunc ReceiverMain = (ReceiverMainFunc)dlsym(receiverLib, "ReceiverMain");

    if (!WaitForEventSender || !GetData || !MakeFrame || !SendFrame ||
        !WaitForEventReceiver || !ReceiveFrame || !ExtractData || !DeliverData ||
        !SenderMain || !ReceiverMain) {
        std::cerr << "Failed to load functions!" << std::endl;
        return 1;
    }

    std::cout << "Running sender..." << std::endl;
    SenderMain();

    std::cout << "Running receiver..." << std::endl;
    ReceiverMain();

    dlclose(senderLib);
    dlclose(receiverLib);

    return 0;
}

