// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from demo.djinni

#pragma once

#include "action_result.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeActionResult final {
public:
    using CppType = ::demo::ActionResult;
    using JniType = jobject;

    using Boxed = NativeActionResult;

    ~NativeActionResult();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeActionResult();
    friend ::djinni::JniClass<NativeActionResult>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/wechat/clibs/ActionResult") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ILjava/lang/String;Ljava/lang/String;)V") };
    const jfieldID field_mCode { ::djinni::jniGetFieldID(clazz.get(), "mCode", "I") };
    const jfieldID field_mMsg { ::djinni::jniGetFieldID(clazz.get(), "mMsg", "Ljava/lang/String;") };
    const jfieldID field_mData { ::djinni::jniGetFieldID(clazz.get(), "mData", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
