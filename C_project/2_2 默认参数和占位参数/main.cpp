//
//  main.cpp
//  2_2默认参数和占位参数
//
//  Created by 倪浩鹏 on 2020/1/30.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

void fun1(int a, int b, int c = 10){  // 66为默认参数，如果存在多个默认参数，有默认值的必须写后面，这样可以不传进来
    cout << "a +b + c = " << (a + b + c) << endl;
}

void fun2(int a, int = 0){      // 占位参数
    cout << "a = " << a << endl;
}

int main(int argc, const char * argv[]) {
    int a = 4;
    int b = 5;
    int c = 1;
    // 利用默认值的情况
    fun1(a, b);
    fun1(a, b, c);
    fun2(a, b);
    fun2(a);
    return 0;
}
