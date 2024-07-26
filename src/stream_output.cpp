#include "stream_output.h"

StreamOutput::StreamOutput(const char* ip, int port) {
    out_sock = srt_create_socket();
    sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    inet_pton(AF_INET, ip, &sa.sin_addr);

    srt_connect(out_sock, (sockaddr*)&sa, sizeof sa);
}

StreamOutput::~StreamOutput() {
    srt_close(out_sock);
}

void StreamOutput::send(AVPacket* packet) {
    // Logic to send packet to the output stream
}
