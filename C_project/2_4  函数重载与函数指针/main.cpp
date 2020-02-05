//
//  main.cpp
//  2_4 函数重载与函数指针
//
//  Created by 倪浩鹏 on 2020/1/30.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


#include <iostream>
using namespace std;
// 函数指针要和重载相对应，在函数指针赋值的时候，是会发生函数匹配重载的

void func1(int a, int b){
    cout << "fun1:" << (a+b) << endl;
}

void func1(int a, int b, int c){
    cout << "fun2" << endl;
}

// 方法1：定义一种函数类型
typedef void(MY_FUNC) (int, int);

// 方法2：定义一种指向这种函数类型的指针类型
typedef void(*MY_FUNC_P) (int, int, int);

int main(int argc, const char * argv[]) {
    // 方法1
    MY_FUNC *fp = nullptr;
    fp = func1;
    fp(1, 2);
    (*fp)(10, 20);
    
    // 方法2
    MY_FUNC_P fp1 = nullptr;
    fp1 = func1;
    fp1(2, 3, 4);
    
    // 方法3
    void(*fp2)(int, int) = nullptr;
    fp2 = func1;
    fp2(3, 4);
    return 0;
}
