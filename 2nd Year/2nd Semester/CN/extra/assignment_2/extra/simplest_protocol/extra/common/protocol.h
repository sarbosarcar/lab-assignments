#ifndef PROTOCOL_H
#define PROTOCOL_H

typedef struct Frame {
    int header;
    char* data;
    int dataLength;
} Frame;

#endif 
