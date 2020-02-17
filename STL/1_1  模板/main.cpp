//
//  main.cpp
//  1_1  模板
//
//  Created by 倪浩鹏 on 2020/2/17.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

// 模板技术：类型参数化，编写代码时可以忽略类型
// 普通函数可以进行自动类型转化，模板函数不能进行，必须严格类型匹配，C++编译器优先考虑普通函数
// g++ -E A.cpp -o A.i      预编译
// g++ -S A.i -o A.s        编译
// g++ -c A.s -o A.o        生成目标文件
// g++ A.o -o A
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
