#ifndef STREAM_OUTPUT_H
#define STREAM_OUTPUT_H

#include <srt/srt.h>
#include <libavformat/avformat.h>

class StreamOutput {
public:
    StreamOutput(const char* ip, int port);
    ~StreamOutput();
    void send(AVPacket* packet);

private:
    SRTSOCKET out_sock;
};

#endif // STREAM_OUTPUT_H
