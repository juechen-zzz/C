//
//  main.cpp
//  C++增强部分
//
//  Created by 倪浩鹏 on 2020/1/20.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;
// C++语言对全局变量的检测增强了

void test(){
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

int main(int argc, const char * argv[]) {
    cout << "Hello, World!" << endl;
    test();
    test2();
    return 0;
}
