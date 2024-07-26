#ifndef SRT_RECEIVER_H
#define SRT_RECEIVER_H

#include <srt/srt.h>

class SrtReceiver {
public:
    SrtReceiver(int port);
    ~SrtReceiver();
    SRTSOCKET acceptConnection();
    int receiveData(SRTSOCKET sock, char* buffer, int size);

private:
    SRTSOCKET server_sock;
};

#endif // SRT_RECEIVER_H
