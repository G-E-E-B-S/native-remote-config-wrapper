set(PROJ_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/cpp/firebase_remote_config.cpp
    ${CMAKE_CURRENT_LIST_DIR}/cpp/listener/RemoteConfigListener.cpp
    ${CMAKE_CURRENT_LIST_DIR}/bindings/manual/RemoteConfigJSHelper.cpp
)

if (COCOS_3_7_PLUS)
    list(APPEND PROJ_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/bindings/auto/3.7.x/jsb_native_remote_config_auto.cpp
    )
elseif(COCOS_3_X_PLUS)
    list(APPEND PROJ_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/bindings/auto/3.x.x_3.6.x/jsb_native_remote_config_auto.cpp
    )
endif()

add_library(native_remote_config STATIC ${PROJ_SOURCES})

target_include_directories(native_remote_config PUBLIC
    ${COCOS_X_PATH}
    ${COCOS_X_PATH}/cocos
    ${COCOS_X_PATH}/cocos/renderer
    ${platform_spec_path}/include/v8
    ${FIREBASE_CPP_DIR}/include
    ${JSB_HELPER_INCLUDE_DIR}
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/cpp
)
target_link_libraries(native_remote_config
    PRIVATE jsb-helper
    PRIVATE ${FIREBASE_CPP_DIR}/libs/android/${ANDROID_ABI}/libfirebase_remote_config.a)