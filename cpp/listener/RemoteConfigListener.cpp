#include "RemoteConfigListener.h"

namespace remoteconfig {
    
    void RemoteConfigListener::onRemoteConfigInit() {
        CC_LOG_DEBUG("Listener onRemoteConfigInit");
        RUN_ON_MAIN_THREAD_BEGIN
            MAKE_V8_HAPPY

            se::ValueArray args;
            invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void RemoteConfigListener::onRemoteConfigLoaded(const cc::ValueMap &data) {
        CC_LOG_DEBUG("Listener onRemoteConfigLoaded");
        RUN_ON_MAIN_THREAD_BEGIN
            MAKE_V8_HAPPY

            se::ValueArray args;
            se::Value dataVal;
            ccvaluemap_to_seval(data, &dataVal);
            args.push_back(dataVal);
            invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }

    void RemoteConfigListener::onRemoteConfigLoadFailed() {
        CC_LOG_DEBUG("Listener onRemoteConfigLoadFailed");
        RUN_ON_MAIN_THREAD_BEGIN
            MAKE_V8_HAPPY

            se::ValueArray args;
            invokeJSFun(funcName, args);

        RUN_ON_MAIN_THREAD_END
    }
}