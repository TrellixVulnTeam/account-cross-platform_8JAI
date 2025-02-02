//
// Created by melon on 2019/2/28.
//

#include "aes.h"
#include "aes_encryptor.h"

#include "../../cpp/utils/log_utils.h"

#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <time.h>

using namespace std;
using namespace cipher_center;

#define LOGD(msg)  utils::LogUtil::LOGD(msg);

AesEncryptor::AesEncryptor(unsigned char* key)
{
    m_pEncryptor = new AES(key);
}


AesEncryptor::~AesEncryptor(void)
{
    delete m_pEncryptor;
}

void AesEncryptor::Byte2Hex(const unsigned char* src, int len, char* dest) {
    for (int i=0; i<len; ++i) {
        snprintf(dest + i * 2, 3, "%02X", src[i]);
    }
}

void AesEncryptor::Hex2Byte(const char* src, int len, unsigned char* dest) {
    int length = len / 2;
    for (int i=0; i<length; ++i) {
        dest[i] = Char2Int(src[i * 2]) * 16 + Char2Int(src[i * 2 + 1]);
    }
}

int AesEncryptor::Char2Int(char c) {
    if ('0' <= c && c <= '9') {
        return (c - '0');
    }
    else if ('a' <= c && c<= 'f') {
        return (c - 'a' + 10);
    }
    else if ('A' <= c && c<= 'F') {
        return (c - 'A' + 10);
    }
    return -1;
}

string AesEncryptor::EncryptString(string strInfor) {
    double diff_seconds = (double)(clock());

    int nLength = strInfor.length();
    int spaceLength = 16 - (nLength % 16);
    unsigned char* pBuffer = new unsigned char[nLength + spaceLength];
    memset(pBuffer, '\0', nLength + spaceLength);
    memcpy(pBuffer, strInfor.c_str(), nLength);

    m_pEncryptor->Cipher(pBuffer, nLength + spaceLength);

	stringstream ss;
	ss << ((double)(clock() - diff_seconds) / CLOCKS_PER_SEC  * 1000);
    LOGD("[aes_encryptor.EncryptString] Encrypt Time : " + ss.str() + "ms");

    // 这里需要把得到的字符数组转换成十六进制字符串
    char* pOut = new char[2 * (nLength + spaceLength)];
    memset(pOut, '\0', 2 * (nLength + spaceLength));
    Byte2Hex(pBuffer, nLength + spaceLength, pOut);

    string retValue(pOut);
    delete[] pBuffer;
    delete[] pOut;
    return retValue;
}

string AesEncryptor::DecryptString(string strMessage) {
    

    int nLength = strMessage.length() / 2;
    unsigned char* pBuffer = new unsigned char[nLength];
    memset(pBuffer, '\0', nLength);
    Hex2Byte(strMessage.c_str(), strMessage.length(), pBuffer);

    double diff_seconds = (double)(clock());

    m_pEncryptor->InvCipher(pBuffer, nLength);

    stringstream ss;
	ss << ((double)(clock() - diff_seconds) / CLOCKS_PER_SEC  * 1000);
    LOGD("[aes_encryptor.DecryptString] Decrypt Time : " + ss.str() + "ms");

    string retValue((char*)pBuffer);
    delete[] pBuffer;
    return retValue;
}
