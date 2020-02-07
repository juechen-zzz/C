//
//  main.cpp
//  5_2  小括号操作符重载
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


/*
    将一个对象当做是一个普通函数来调用，称这种对象是仿函数或伪函数（函数对象）
    若重载new和delete，用void * operator new(Size s)
 */

#include <iostream>
using namespace std;


class sqr{
public:
    sqr(int a){
        this->a = a;
    }
    int operator()(int value){
        return value * value;
    }
private:
    int a;
};

int main(int argc, const char * argv[]) {
    sqr s(10);
    int value = s(3);
    cout << value << endl;
    return 0;
}

