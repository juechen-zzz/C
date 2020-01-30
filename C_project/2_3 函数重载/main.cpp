//
//  main.cpp
//  2_3 函数重载
//
//  Created by 倪浩鹏 on 2020/1/30.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 函数的返回值，函数的形参列表（个数、类型和顺序）
// 函数重载：函数名相同，但是参数列表不同，称互为重载
// 函数返回值并不是构成函数重载的定义
// 重载一般不要写默认参数，容易出现歧义
// 如果没有完全匹配的，则调用隐式转换

void fun1(int a, int b){
    cout << "fun1" << endl;
}

void fun1(int a){
    cout << "fun2" << endl;
}

int main(int argc, const char * argv[]) {
    fun1(1, 2);
    fun1(1);
    return 0;
}
