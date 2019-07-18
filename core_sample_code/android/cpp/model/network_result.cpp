//
// Created by melon on 2019/2/3.
//

#include <stdio.h>
#include "network_result.h"
#include <sstream>
//#include <android/log.h>

namespace demo{

    int ReqResult::getCode(){
        return this->code;
    }
    void ReqResult::setCode(std::string code){
        std::string::size_type sz;   // alias of size_t
        int i_dec = std::stoi (code,&sz);
        this->code = i_dec;
    }
    void ReqResult::setCode(int code){
        this->code = code;
    }
    std::string ReqResult::getMsg(){
        return this->msg;
    }
    void ReqResult::setMsg(std::string msg){
        this->msg = msg;
    }
    std::string ReqResult::getData(){
        return this->data;
    }

    void ReqResult::setData(std::string data){
        this->data = data;
    }

}

