//
//  main.cpp
//  2_6  异常类型和异常对象生命周期
//
//  Created by 倪浩鹏 on 2020/2/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;


class MyException{
public:
    // 有参构造
    MyException(const char *str){
        this->error = new char[strlen(str) + 1];
        strcpy(this->error, str);
    }
    // 拷贝构造
    MyException(const MyException &another){
        this->error = new char[strlen(another.error) + 1];
        strcpy(this->error, another.error);
    }
    // =操作符重载
    MyException& operator=(const MyException &another){
        if (this->error != nullptr) {
            delete[] this->error;
            this->error = nullptr;
        }
        this->error = new char[strlen(another.error) + 1];
        strcpy(this->error, another.error);
        return *this;
    }
    // 成员函数
    void what(){
        cout << this->error << endl;
    }
    // 析构函数
    ~MyException(){
        if (this->error != nullptr) {
            delete[] this->error;
            this->error = nullptr;
        }
    }
private:
    char *error;
};


void func(){
    // throw 1;                     // 抛出int类型
    // throw "abc";                 // 抛出const char *类型
    throw MyException("123");            // 抛出对象异常
}


int main(int argc, const char * argv[]) {
    try {
        func();
    } catch (int a) {
        cout << a << endl;
    } catch (char const *p){
        cout << p << endl;
    } catch (MyException e){        // 拷贝构造，此时存在匿名对象和拷贝构造对象e，所以析构调用会出问题
        e.what();
    }
    return 0;
}
