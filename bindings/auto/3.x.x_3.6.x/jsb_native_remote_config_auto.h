// clang-format off
#pragma once

#include <type_traits>
#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "../../cpp/firebase_remote_config.h"

bool register_all_remoteconfig(se::Object *obj);                   // NOLINT

JSB_REGISTER_OBJECT_TYPE(wrapper::FirebaseRemoteConfig);


extern se::Object *__jsb_wrapper_FirebaseRemoteConfig_proto;   // NOLINT
extern se::Class *__jsb_wrapper_FirebaseRemoteConfig_class;    // NOLINT

bool js_register_wrapper_FirebaseRemoteConfig(se::Object *obj); // NOLINT

SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetBoolean);
SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetDouble);
SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetLong);
SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_GetString);
SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_fetch);
SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_init);
SE_DECLARE_FUNC(js_remoteconfig_FirebaseRemoteConfig_getInstance);
// clang-format on
