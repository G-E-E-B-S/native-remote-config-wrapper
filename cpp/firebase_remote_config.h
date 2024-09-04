#pragma once

#include <cstdint>
#include "include/firebase_app_getter.h"
#include "listener/RemoteConfigListener.h"

namespace remoteconfig
{
    class FirebaseRemoteConfig
    {
        private:
            RemoteConfigListener* _listener;

        public:
            FirebaseRemoteConfig(wrapper::jsbhelper::IFirebaseAppGetter* getter);

        public:
            void setListener(RemoteConfigListener* listener) {_listener = listener;}
            RemoteConfigListener* getListener() {return _listener;}

        public:
            void fetch();
            int64_t GetLong(const char* key, int64_t defaultValue);
            double GetDouble(const char* key, double defaultValue);
            bool GetBoolean(const char* key, bool defaultValue);
            const char* GetString(const char* key, const char* defaultValue);
    };
    
}