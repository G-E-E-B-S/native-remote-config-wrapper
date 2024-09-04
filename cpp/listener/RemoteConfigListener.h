#pragma once

#include "include/JSListenerBase.h"

namespace remoteconfig {
    class RemoteConfigListener: public wrapper::jsbhelper::JSListenerBase
    {
    public:
        RemoteConfigListener(/* args */){}

    public:
        void onRemoteConfigInit();
        void onRemoteConfigLoaded(const cc::ValueMap& data);
        void onRemoteConfigLoadFailed();
    };
}