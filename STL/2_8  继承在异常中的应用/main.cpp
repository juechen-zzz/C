//
//  main.cpp
//  2_8  继承在异常中的应用
//
//  Created by 倪浩鹏 on 2020/2/23.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class BaseMyException{
public:
    virtual void what() = 0;
    virtual ~BaseMyException(){}
};

class TargetSpaceNullException: public BaseMyException{
public:
    virtual void what(){
        cout << "目标空间为空！" << endl;
    }
    ~TargetSpaceNullException(){}
};

class SourceSpaceNullException: public BaseMyException{
public:
    virtual void what(){
        cout << "源空间为空！" << endl;
    }
    ~SourceSpaceNullException(){}
};

void StrCopy(char *target, const char *source){
    if (target == nullptr) {
        throw TargetSpaceNullException();
    }
    if (source == nullptr) {
        throw SourceSpaceNullException();
    }
    // int len = (int)strlen(source);
    while (*source != '\0') {
        *target = *source;
        target++;
        source++;
    }
}

int main(int argc, const char * argv[]) {
    const char *a = "abcdefg";
    char b[1024] = {0};
    try {
        // StrCopy(nullptr, a);
        // StrCopy(b, nullptr);
        StrCopy(b, a);
    } catch (BaseMyException &ex) {
        ex.what();
    }
    cout << b << endl;
    return 0;
}
