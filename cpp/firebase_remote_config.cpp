#include "firebase_remote_config.h"

#include "firebase/remote_config.h"
#include "firebase/util.h"

#include "cocos/base/Log.h"
#include "application/ApplicationManager.h"
#include <base/Value.h>

namespace remote_config = ::firebase::remote_config;
using firebase::remote_config::RemoteConfig;

namespace remoteconfig
{
    RemoteConfig *rc_ = nullptr;

    cc::Value GetValueFromVariant(const firebase::Variant& variant) {
        if(variant.is_bool()) {
            return cc::Value(variant.bool_value());
        } else if(variant.is_int64()) {
            return cc::Value(variant.is_int64());
        } else if(variant.is_double()) {
            return cc::Value(variant.double_value());
        } else if(variant.is_string()) {
            return cc::Value(variant.string_value());
        } else if(variant.is_vector()) {
            cc::ValueVector values;
            for(auto v : variant.vector()) {
                values.push_back(GetValueFromVariant(v));
            }
            return cc::Value(values);
        }
    }

    cc::ValueMap GetValueMapFromVarints(const std::map<std::string, firebase::Variant>& variants) {
        cc::ValueMap valueMap;
        for (auto variant : variants) {
            valueMap[variant.first] = GetValueFromVariant(variant.second);
        }
        return valueMap;
    }

    void onDataLoaded(const firebase::Future<bool> &result, void *data) {
        auto remoteConfig = static_cast<FirebaseRemoteConfig *>(data);
        auto success = *result.result();
        CC_LOG_DEBUG(">>>> firebase remote config data loaded: %d", success);
        const cc::ValueMap &valueMap = GetValueMapFromVarints(rc_->GetAll());
        remoteConfig->getListener()->onRemoteConfigLoaded((valueMap));
//        if(success) {
//            const cc::ValueMap &valueMap = GetValueMapFromVarints(rc_->GetAll());
//            remoteConfig->getListener()->onRemoteConfigLoaded((valueMap));
//        } else {
//            remoteConfig->getListener()->onRemoteConfigLoadFailed();
//        }
    }

    void OnFetcCompleted(const firebase::Future<void>& fetchResult, void* data) {
        CC_LOG_DEBUG(">>>> firebase remote config fetch complted");
        auto activateFuture = rc_->Activate();
        activateFuture.OnCompletion(onDataLoaded, data);
    }

    void  onInitCompleted(const firebase::Future<void>& fetchResult, void* data) {
        CC_LOG_DEBUG(">>>> firebase remote config init done");
        auto remoteConfig = static_cast<FirebaseRemoteConfig *>(data);
        //remoteConfig->getListener()->onRemoteConfigInit();
//        remoteConfig->fetch();
    }

    firebase::InitResult onRemoteConfigInit(firebase::App *app, void *target) {
        RemoteConfig **rc_ptr = reinterpret_cast<RemoteConfig **>(target);
        *rc_ptr = RemoteConfig::GetInstance(app);
        CC_LOG_DEBUG(">>>> firebase remote config init");
        //getInstance()->fetch();
        return firebase::kInitResultSuccess;
    }

    FirebaseRemoteConfig::FirebaseRemoteConfig(wrapper::jsbhelper::IFirebaseAppGetter *getter) {
        ::firebase::App *app = getter->getApp();
        ::firebase::ModuleInitializer initializer;
        void *ptr = nullptr;
        ptr = &rc_;
        firebase::Future<void> initFuture = initializer.Initialize(app, ptr, onRemoteConfigInit);
        initFuture.OnCompletion(onInitCompleted, this);
    }

    void FirebaseRemoteConfig::fetch()
    {
        firebase::Future<void> fetchFuture = rc_->Fetch(0);
        fetchFuture.OnCompletion(OnFetcCompleted, this);
    }

    int64_t FirebaseRemoteConfig::GetLong(const char* key, int64_t defaultValue)
    {
        if (rc_ == nullptr) return defaultValue;
        return rc_->GetLong(key);
    }

    double FirebaseRemoteConfig::GetDouble(const char* key, double defaultValue)
    {
        if (rc_ == nullptr) return defaultValue;
        return rc_->GetDouble(key);
    }

    bool FirebaseRemoteConfig::GetBoolean(const char* key, bool defaultValue)
    {
        if (rc_ == nullptr) return defaultValue;
        return rc_->GetBoolean(key);
    }

    const char* FirebaseRemoteConfig::GetString(const char* key, const char* defaultValue)
    {
        if(rc_ == nullptr) return nullptr;
        return rc_->GetString(key).c_str();
    }
}