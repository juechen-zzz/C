//
//  main.cpp
//  C++增强部分
//
//  Created by 倪浩鹏 on 2020/1/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
#include "test.hpp"
using namespace std;

// C++语言对全局变量的检测增强了

void test1(){
    bool flag;          // 新增的bool类型
    flag = true;        // true为1，false为0
    if (flag){
        cout << "Yes!" << endl;
    }
    cout << "size: " << sizeof(flag) << endl;       // 大小为1个字节
}

void test2(){
    int a = 10;
    int b = 20;
    int c = 0;
    
    c = a > b ? a : b;          // 三目运算符(c语言中的写法，C++中可以作为左值，返回的是a的引用)
    cout << "c = " << c << endl;
    
    // *(a < b ? &a : &b) = 50;    // 返回的变成了a或者b的地址，然后赋值(c语言)
    (a < b ? a : b) = 50;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void test3(){
    const int a = 10;
    // int arrat_test[a];
    
    int *p = (int*)&a;      // 如果对一个常量取地址，编译器会临时开辟一个空间temp，让这个指针存放这个临时空间的地址
    *p = 20;                // 改变的是temp变量
    
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
}

// 枚举,返回所要找的值对应的索引
enum season{
    spring = 0,
    summer,
    autumn,
    winter
};

void test4(){
    enum season s = winter;
    cout << "s = " << s << endl;
}

struct student{
    int id;
    char name[64];
};
void printf1(struct student &s){
    cout << s.id << " " << s.name << endl;
}


int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    test4();
    test5();
    
    student s1 = {1, "A"};
    printf1(s1);
    
    // const增强部分，const定义常量-->代表只读，不可修改
    // 和#define宏定义不同，宏定义是在预处理阶段，const是在编译阶段
    //const int *z1;                  // 指针可以修改，但是指针指向的区域内部不可修改
    //int *const z2 = nullptr;        // 指针不可修改，但是指针指向的区域内部可以修改
    return 0;
}
