//
// Created by Xana Hopper on 2019-03-13.
//

#ifndef MERLIN_TYPE_H
#define MERLIN_TYPE_H

#include <string>

namespace ml {

typedef int64_t Time;

struct Clip {
    std::string filepath;
    Time startTime;
    Time endTime;
};

struct Timeline {

    Timeline() : clip(nullptr) {}

    std::unique_ptr<Clip> clip;

    Time duration() {
        return clip ? clip->endTime - clip->startTime : 0;
    }
};

struct Rational {
    int num;    // 分子
    int den;    // 分母
};

struct Frame {
    Time pts;
    Time dts;
    int width;
    int height;
    Rational PAR;   // pixel aspect ratio
};

struct Sample {
    Time pts;
    Time dts;
};
}

#endif //MERLIN_TYPE_H

