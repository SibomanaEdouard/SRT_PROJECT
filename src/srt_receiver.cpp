#include "srt_receiver.h"
#include <iostream>

SrtReceiver::SrtReceiver(int port) {
    srt_startup();
    server_sock = srt_create_socket();
    sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;

    srt_bind(server_sock, (sockaddr*)&sa, sizeof sa);
    srt_listen(server_sock, 2);
}

SrtReceiver::~SrtReceiver() {
    srt_close(server_sock);
    srt_cleanup();
}

SRTSOCKET SrtReceiver::acceptConnection() {
    sockaddr_in their_addr;
    int addrlen = sizeof their_addr;
    return srt_accept(server_sock, (sockaddr*)&their_addr, &addrlen);
}

int SrtReceiver::receiveData(SRTSOCKET sock, char* buffer, int size) {
    return srt_recvmsg(sock, buffer, size);
}
