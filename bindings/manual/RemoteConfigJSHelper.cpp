#include "RemoteConfigJSHelper.h"
#include "cpp/firebase_remote_config.h"
#include "cpp/listener/RemoteConfigListener.h"

namespace {
    remoteconfig::FirebaseRemoteConfig* s_remoteConfig = nullptr;
}

static bool js_RemoteConfigJS_setListener(se::State& s) {
    const auto& args = s.args();
    int argc = (int)args.size();
    auto targetArgc = 1;
    if (argc == targetArgc)
    {
        static remoteconfig::RemoteConfigListener* listener = nullptr;
        if (!listener) {
            listener = new (std::nothrow) remoteconfig::RemoteConfigListener();
            s_remoteConfig->setListener(listener);
        }
        listener->setJSDelegate(args[0]);

        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, targetArgc);
    return false;
}
SE_BIND_FUNC(js_RemoteConfigJS_setListener)

static bool js_RemoteConfigJS_getInstance(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();
    auto expected = 1;
    if (argc == expected)
    {
        if (s_remoteConfig == nullptr) {
            wrapper::jsbhelper::IFirebaseAppGetter* getter = nullptr;
            seval_to_native_ptr(args[0], &getter);
            s_remoteConfig = new remoteconfig::FirebaseRemoteConfig(getter);
        }
        auto ok = native_ptr_to_seval<remoteconfig::FirebaseRemoteConfig>((remoteconfig::FirebaseRemoteConfig*)s_remoteConfig, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RemoteConfigJS_getInstance : Error create instance");
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, expected);
    return false;
}
SE_BIND_FUNC(js_RemoteConfigJS_getInstance)

bool register_all_remoteconfig_JS_helper(se::Object* obj) {

    auto pluginValue = wrapper::jsbhelper::getPluginValue(obj, "remoteconfig");
    auto plugin = pluginValue.toObject();
    plugin->defineFunction("getInstance", _SE(js_RemoteConfigJS_getInstance));
    plugin->defineFunction("setListener", _SE(js_RemoteConfigJS_setListener));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}