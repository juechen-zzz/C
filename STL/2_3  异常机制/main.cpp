//
//  main.cpp
//  2_3  异常机制
//
//  Created by 倪浩鹏 on 2020/2/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    C++异常机制是跨函数的，必须处理
 */


#include <iostream>
using namespace std;

// 异常基本语法
int divide1(int x, int y){
    if (y == 0) {
        throw y;        //抛异常
    }
    return x / y;
}

void CallDivide(int x, int y){
    divide1(x, y);
}


int main(int argc, const char * argv[]) {
    try {                                        // 试着捕获异常
        // divide1(10, 0);
        CallDivide(10, 0);
    } catch (int e) {                              // 根据类型进行匹配(int)
        cout << "除数为: " << e << endl;
    }
    return 0;
}
