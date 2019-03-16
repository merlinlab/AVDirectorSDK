//
// Created by Xana Hopper on 2019-03-13.
//

#ifndef MERLIN_CORE_H
#define MERLIN_CORE_H

#include <queue>
#include "type.hpp"
#include "Demuxer.hpp"
#include "Decoder.hpp"
#include "Encoder.hpp"
#include "Muxer.hpp"

namespace ml {
class Core {
public:
    typedef void (*FrameRenderedCallback)(Frame *pFrame);

public:
    // disable copy constructor
    Core(const Core &) = delete;

    Core(const Core &&) = delete;

    // disable copy operator
    Core operator=(const Core &) = delete;

    Core operator=(const Core &&) = delete;

    Core();

    ~Core();

public:

    Timeline createTimeline();

    void compileTimeline(Timeline &timeline);

private:
    std::queue<Frame> frameQueue;
    std::queue<Sample> sampleQueue;

    std::unique_ptr<Demuxer> demuxer;
    std::unique_ptr<Decoder> decoder;
    std::unique_ptr<Encoder> encoder;
    std::unique_ptr<Muxer> muxer;

private:
    FrameRenderedCallback frameRenderedCallback;
};
}


#endif //MERLIN_CORE_H
