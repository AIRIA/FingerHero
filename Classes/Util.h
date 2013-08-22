//
//  Util.h
//  FingerHero
//
//  Created by AIRIA on 14-8-21.
//
//

#ifndef __FingerHero__Util__
#define __FingerHero__Util__

#include "CommonHeaders.h"

#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

#endif

class Util {
public:

};

#if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)

	extern "C" {

		JNIEXPORT void JNICALL Java_com_giant_jni_JniBrige_showExit(JNIEnv *env,jobject thiz)
		{
            isShowExit = !isShowExit;
		}
	}
#endif

#endif /* defined(__FingerHero__Util__) */
