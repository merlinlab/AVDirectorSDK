//
// Created by Xana Hopper on 2019-03-13.
//

#include "Core.hpp"

namespace ml {

Core::Core()
:demuxer(nullptr), decoder(nullptr), encoder(nullptr), muxer(nullptr) {

}

Core::~Core() = default;

Timeline Core::createTimeline() {
    return Timeline();
}

void Core::compileTimeline(Timeline &timeline) {

}

}
