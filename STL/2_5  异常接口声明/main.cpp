//
//  main.cpp
//  2_5  异常接口声明
//
//  Created by 倪浩鹏 on 2020/2/22.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    1 为了加强函数的可读性，可以在函数声明中列出可能抛出异常的所有类型。例：void func() throw(A, B, C)
    2 若声明中没有包含异常接口声明，则函数可以抛出任意类型的异常
    3 一个不抛任何异常类型的函数可以声明为：void func() throw()
    4 如果一个函数抛出了在异常接口声明中不允许抛出的异常，unexcepted函数会被调用，该函数默认调用terminate函数中断程序
 */

#include <iostream>
using namespace std;

void func() throw(int, float, char){
    // throw 'a';
    throw 10;
}

int main(int argc, const char * argv[]) {
    try {
        func();
    } catch (char str) {
        cout << str << endl;
    } catch (int a) {
        cout << a << endl;
    } catch (float e) {
        cout << e << endl;
    } catch (...){
        cout << "未知" << endl;
    }
    return 0;
}
