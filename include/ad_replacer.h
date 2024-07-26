#ifndef AD_REPLACER_H
#define AD_REPLACER_H

#include <libavformat/avformat.h>

class AdReplacer {
public:
    AdReplacer(const char* ad_file);
    ~AdReplacer();
    void replace(AVPacket* packet);

private:
    AVFormatContext* ad_format_ctx;
};

#endif // AD_REPLACER_H
