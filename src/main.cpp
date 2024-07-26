#include "srt_receiver.h"
#include "scte35_detector.h"
#include "ad_replacer.h"
#include "stream_output.h"

int main() {
    SrtReceiver receiver(9000);
    Scte35Detector detector;
    AdReplacer adReplacer("ads/ad1.mp4");
    StreamOutput output("127.0.0.1", 9001);

    SRTSOCKET sock = receiver.acceptConnection();

    char buffer[188];
    while (true) {
        int size = receiver.receiveData(sock, buffer, sizeof(buffer));
        if (size <= 0) continue;

        AVPacket packet;
        av_init_packet(&packet);
        packet.data = (uint8_t*)buffer;
        packet.size = size;

        if (detector.detect(&packet)) {
            adReplacer.replace(&packet);
        }

        output.send(&packet);
        av_packet_unref(&packet);
    }

    return 0;
}
