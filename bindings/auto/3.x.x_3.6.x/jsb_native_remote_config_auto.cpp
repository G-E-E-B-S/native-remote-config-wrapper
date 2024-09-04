
// clang-format off
#include "jsb_native_remote_config_auto.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/bindings/manual/jsb_global.h"
#include "firebase_remote_config.h"

#ifndef JSB_ALLOC
#define JSB_ALLOC(kls, ...) new (std::nothrow) kls(__VA_ARGS__)
#endif

#ifndef JSB_FREE
#define JSB_FREE(ptr) delete ptr
#endif

#if CC_DEBUG
static bool js_remoteconfig_getter_return_true(se::State& s) // NOLINT(readability-identifier-naming)
{
    s.rval().setBoolean(true);
    return true;
}
SE_BIND_PROP_GET(js_remoteconfig_getter_return_true)
#endif
se::Object* __jsb_wrapper_FirebaseRemoteConfig_proto = nullptr; // NOLINT
se::Class* __jsb_wrapper_FirebaseRemoteConfig_class = nullptr;  // NOLINT

static bool js_remoteconfig_FirebaseRemoteConfig_GetBoolean(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<wrapper::FirebaseRemoteConfig>(s);
    // SE_PRECONDITION2(cobj, false, "Invalid Native Object");
    if (nullptr == cobj) return true;
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        HolderType<const char*, false> arg0 = {};
        HolderType<bool, false> arg1 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        ok &= sevalue_to_native(args[1], &arg1, s.thisObject());
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        bool result = cobj->GetBoolean(arg0.value(), arg1.value());
        ok &= nativevalue_to_se(result, s.rval(), nullptr /*ctx*/);
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        SE_HOLD_RETURN_VALUE(result, s.thisObject(), s.rval());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetBoolean)

static bool js_remoteconfig_FirebaseRemoteConfig_GetDouble(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<wrapper::FirebaseRemoteConfig>(s);
    // SE_PRECONDITION2(cobj, false, "Invalid Native Object");
    if (nullptr == cobj) return true;
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        HolderType<const char*, false> arg0 = {};
        HolderType<double, false> arg1 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        ok &= sevalue_to_native(args[1], &arg1, s.thisObject());
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        double result = cobj->GetDouble(arg0.value(), arg1.value());
        ok &= nativevalue_to_se(result, s.rval(), nullptr /*ctx*/);
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        SE_HOLD_RETURN_VALUE(result, s.thisObject(), s.rval());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetDouble)

static bool js_remoteconfig_FirebaseRemoteConfig_GetLong(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<wrapper::FirebaseRemoteConfig>(s);
    // SE_PRECONDITION2(cobj, false, "Invalid Native Object");
    if (nullptr == cobj) return true;
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        HolderType<const char*, false> arg0 = {};
        HolderType<int64_t, false> arg1 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        ok &= sevalue_to_native(args[1], &arg1, s.thisObject());
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        int64_t result = cobj->GetLong(arg0.value(), arg1.value());
        ok &= nativevalue_to_se(result, s.rval(), nullptr /*ctx*/);
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        SE_HOLD_RETURN_VALUE(result, s.thisObject(), s.rval());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetLong)

static bool js_remoteconfig_FirebaseRemoteConfig_GetString(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<wrapper::FirebaseRemoteConfig>(s);
    // SE_PRECONDITION2(cobj, false, "Invalid Native Object");
    if (nullptr == cobj) return true;
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        HolderType<const char*, false> arg0 = {};
        HolderType<const char*, false> arg1 = {};
        ok &= sevalue_to_native(args[0], &arg0, s.thisObject());
        ok &= sevalue_to_native(args[1], &arg1, s.thisObject());
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        const char* result = cobj->GetString(arg0.value(), arg1.value());
        ok &= nativevalue_to_se(result, s.rval(), nullptr /*ctx*/);
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        SE_HOLD_RETURN_VALUE(result, s.thisObject(), s.rval());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetString)

static bool js_remoteconfig_FirebaseRemoteConfig_fetch(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<wrapper::FirebaseRemoteConfig>(s);
    // SE_PRECONDITION2(cobj, false, "Invalid Native Object");
    if (nullptr == cobj) return true;
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->fetch();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_fetch)

static bool js_remoteconfig_FirebaseRemoteConfig_init(se::State& s) // NOLINT(readability-identifier-naming)
{
    auto* cobj = SE_THIS_OBJECT<wrapper::FirebaseRemoteConfig>(s);
    // SE_PRECONDITION2(cobj, false, "Invalid Native Object");
    if (nullptr == cobj) return true;
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->init();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_init)

static bool js_remoteconfig_FirebaseRemoteConfig_getInstance_static(se::State& s) // NOLINT(readability-identifier-naming)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        wrapper::FirebaseRemoteConfig* result = wrapper::FirebaseRemoteConfig::getInstance();
        ok &= nativevalue_to_se(result, s.rval(), nullptr /*ctx*/);
        SE_PRECONDITION2(ok, false, "Error processing arguments");
        SE_HOLD_RETURN_VALUE(result, s.thisObject(), s.rval());
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_remoteconfig_FirebaseRemoteConfig_getInstance_static)

bool js_register_remoteconfig_FirebaseRemoteConfig(se::Object* obj) // NOLINT(readability-identifier-naming)
{
    auto* cls = se::Class::create("FirebaseRemoteConfig", obj, nullptr, nullptr);

#if CC_DEBUG
    cls->defineStaticProperty("isJSBClass", _SE(js_remoteconfig_getter_return_true), nullptr);
#endif
    cls->defineFunction("GetBoolean", _SE(js_remoteconfig_FirebaseRemoteConfig_GetBoolean));
    cls->defineFunction("GetDouble", _SE(js_remoteconfig_FirebaseRemoteConfig_GetDouble));
    cls->defineFunction("GetLong", _SE(js_remoteconfig_FirebaseRemoteConfig_GetLong));
    cls->defineFunction("GetString", _SE(js_remoteconfig_FirebaseRemoteConfig_GetString));
    cls->defineFunction("fetch", _SE(js_remoteconfig_FirebaseRemoteConfig_fetch));
    cls->defineFunction("init", _SE(js_remoteconfig_FirebaseRemoteConfig_init));
    cls->defineStaticFunction("getInstance", _SE(js_remoteconfig_FirebaseRemoteConfig_getInstance_static));
    cls->install();
    JSBClassType::registerClass<wrapper::FirebaseRemoteConfig>(cls);

    __jsb_wrapper_FirebaseRemoteConfig_proto = cls->getProto();
    __jsb_wrapper_FirebaseRemoteConfig_class = cls;


    se::ScriptEngine::getInstance()->clearException();
    return true;
}
bool register_all_remoteconfig(se::Object* obj)    // NOLINT
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("wrapper_rc", &nsVal, true))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("wrapper_rc", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_remoteconfig_FirebaseRemoteConfig(ns);
    return true;
}

// clang-format on