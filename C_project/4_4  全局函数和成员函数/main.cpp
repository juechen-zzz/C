//
//  main.cpp
//  4_4  全局函数和成员函数
//
//  Created by 倪浩鹏 on 2020/2/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class A{
public:
    A(int a, int b){
        this->a = a;
        this->b = b;
    }
    void printT(){
        cout << "a = " << this->a << ", b = " << this->b << endl;
    }
    int getA(){
        return this->a;
    }
    int getB(){
        return this->b;
    }
    // 方法二：成员函数
    // 如果想返回一个对象的本身，在成员函数中用*this返回
    A A_add_2(A &another){
        A tmp(this->a + another.getA(), this->b + another.getB());
        return tmp;
    }
    // 引用很关键
    A &A_add_3(A &another){
        this->a += another.getA();
        this->b += another.getB();
        return *this;
    }
private:
    int a;
    int b;
};

// 方法一：全局函数
A A_add(A &a1, A &a2){
    A tmp(a1.getA() + a2.getA(), a1.getB() + a2.getB());
    return tmp;
}

int main(int argc, const char * argv[]) {
    A a1(10, 20);
    A a2(100, 200);
    
    // 法一：全局函数
    A a3 = A_add(a1, a2);
    a3.printT();
    
    // 法二：成员函数
    A a4 = a2.A_add_2(a1);
    a4.printT();
    
    // 如果想用一个对象连续调用成员方法，每次都会改变对象本身，成员方法需要返回引用
    a1.A_add_3(a2).A_add_3(a2);
    
    a1.printT();
    a2.printT();
    return 0;
}

