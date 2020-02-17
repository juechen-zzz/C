//
//  main.cpp
//  1_1  函数模板
//
//  Created by 倪浩鹏 on 2020/2/17.
//  Copyright © 2020 nihaopeng. All rights reserved.
//
/*
    1 编译器并不是把函数模板处理成能处理任何类型的函数
    2 函数模板会根据具体类型产生不同的函数
    3 编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译
 */

#include <iostream>
using namespace std;

// 模板技术：类型参数化，编写代码时可以忽略类型
// 函数模板->模板函数->被调用
// 普通函数可以进行自动类型转化，模板函数不能进行，必须严格类型匹配，C++编译器优先考虑普通函数
// 为了让编译器区分，加template关键字，且只对template后的第一个函数有效
template<class T>   // template<typename T>
void MySwap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}


int main(int argc, const char * argv[]) {
    int a = 11;
    int b = 22;
    
    // 1 自动类型d推导
    MySwap(a, b);
    cout << a << " " << b << endl;
    
    // 2 显式指定类型，和普通函数同名时优先普通函数，除非MySwap<>(a, b)这样
    MySwap<int>(a, b);
    cout << a << " " << b << endl;
    return 0;
}
/*
 命令行运行的全过程：
 // g++ -E A.cpp -o A.i      预编译
 // g++ -S A.i -o A.s        编译
 // g++ -c A.s -o A.o        生成目标文件
 // g++ A.o -o A
 */
