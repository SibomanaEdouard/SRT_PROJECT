#ifndef SCTE35_DETECTOR_H
#define SCTE35_DETECTOR_H

#include <libavformat/avformat.h>

class Scte35Detector {
public:
    Scte35Detector();
    ~Scte35Detector();
    bool detect(AVPacket* packet);

private:
    int scte35_stream_index;
};

#endif // SCTE35_DETECTOR_H
