#include <jni.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include "Md5.h"
/*MD5::MD5() {
    void GenerateMD5(unsigned char* buffer,int bufferlen);
    char* ToString();
}*/
extern "C" {

/*char* stringChar(JNIEnv *env,char *str){


    jclass str_cls=(*env)->FindClass(env,"java/lang/String");
    jmethodID jmid=(*env)->GetMethodID(env,str_cls,"<init>","([BLjava/lang/String:)V");

    jbyteArray bytes=(*env)->NewByteArray(env,strlen(str));
    // 将字符串从0开始拷贝到bytes中
    (*env)->SetByteArrayRegion(env,bytes,0,strlen(str),str);

    jstring strencode=(*env)->NewStringUTF(env,"GB2312");

    return (*env)->NewObject(env,str_cls,jmid,bytes,strencode);



}*/
const char *key = "key=2ED63657C9DB401C733C128C1D88DEAA";

JNIEXPORT jstring JNICALL
Java_com_cxy_myndk_Cmd5Utils_stringFromJNI(
        JNIEnv *env,
        jobject /* this */, jstring str) {

    const char *s = env->GetStringUTFChars(str, 0);

    char *buf = new char[strlen(s) + 1+ strlen(key)];
    strcpy(buf, s);
    strcat(buf,key);
    MD5 md5 = MD5(buf);
    std::string hashStr = md5.hexdigest();
    // char * 转string
    jstring j_temp = env->NewStringUTF(hashStr.data());
// 释放本地字符串资源
    (env)->ReleaseStringUTFChars(str,s);
// 释放指针指向的内存资源
    delete(buf);
    buf = NULL;
    return j_temp;//env->NewStringUTF(hashStr.data());
}

}