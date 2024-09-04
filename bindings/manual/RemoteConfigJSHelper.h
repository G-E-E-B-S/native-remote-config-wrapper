#ifndef SPOTMATCH_REMOTECONFIGJSHELPER_H
#define SPOTMATCH_REMOTECONFIGJSHELPER_H
#if CC_VERSION_3_X
#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#else
#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#endif

namespace se {
    class Object;
}

bool register_all_remoteconfig_JS_helper(se::Object* obj);
#endif //SPOTMATCH_REMOTECONFIGJSHELPER_H
