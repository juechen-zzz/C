//
//  main.cpp
//  2_1 内联函数
//
//  Created by 倪浩鹏 on 2020/1/30.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 宏函数定义
// 宏函数缺点为：传参不能变通，如果调用时输入的是a++，则会出现返回a++的情况，没有语法检测能力
#define MAX1(a, b) \
    ((a) > (b) ? (a) : (b))

int max1(int a, int b){
    return (a > b) ? a : b;
}

// 内联函数定义:省略了压栈和出栈过程，在频繁使用时会有效
inline void plus1(int a, int b){
    cout << "a + b = " << a+b << endl;
}

int main(int argc, const char * argv[]) {
    int a = 10;
    int b = 11;
    int c = max1(a, b);
    cout << "c = " << c << endl;
    int d = MAX1(a, b);
    cout << "d = " << d << endl;
    plus1(a, b);
    return 0;
}
