//
//  main.cpp
//  2_7  继承标准库异常
//
//  Created by 倪浩鹏 on 2020/2/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    1 继承标准异常类(exception)
    2 重载父类的what和虚析构函数
    3 因为在栈展开的过程中，要复制异常类型，则要根据在类中添加的成员考虑是否提供自己的复制构造函数
 */

#include <iostream>
#include <exception>
using namespace std;

class Person{
public:
    Person(){
        this->age = 0;
    }
    void setAge(int age){
        if (age <= 0 || age > 100) {
            throw out_of_range("年龄在1-100!");
        }
        this->age = age;
    }

    int age;
};

//class MyOutOfError: public exception{
//public:
//    MyOutOfError(const char *error){
//        this->error = new char[strlen(error) + 1];
//        strcpy(this->error, error);
//    }
//    virtual const char * what() const{
//        return this->error;
//    };
//    ~MyOutOfError(){
//        if (this->error != nullptr) {
//            delete[] this->error;
//            this->error = nullptr;
//        }
//    }
//
//private:
//    char *error;
//};

int main(int argc, const char * argv[]) {
    Person p;
    try {
        p.setAge(1000);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
//    cout << "--------------------------------------" << endl;
//    try {
//        MyOutOfError("my error func");
//    } catch (exception e) {
//        cout << e.what() << endl;
//    }
    return 0;
}
