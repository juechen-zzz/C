//
//  main.cpp
//  3_6  new和delete
//
//  Created by 倪浩鹏 on 2020/2/2.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


// 在软件开发过程中，需要动态的分配和撤销内存空间，C++提供了new和delete运算符
// new和delete时运算符，不是函数，所以执行效率高
// 对应于C语言的malloc和free

#include <iostream>
using namespace std;


// C语言
void test1(){
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    if (p != nullptr) {
        free(p);
        p = nullptr;
    }
    
    int *array_p = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        array_p[i] = i + 1;
        cout << array_p[i] << " ";
    }
    cout << endl;
    if (array_p != nullptr) {
        free(array_p);
        array_p = nullptr;
    }
}

// C++语言
void test2(){
    int *p = new int;       // 开辟一个int的空间，返回地址
    // char *c = new char;
    *p = 10;
    if (p != nullptr) {
        delete p;
        p = nullptr;
    }
    
    int *array_p = new int[10];
    for (int i = 0; i < 10; i++) {
        array_p[i] = i + 1;
        cout << array_p[i] << " ";
    }
    cout << endl;
    if (array_p != nullptr) {
        delete[] array_p;
        array_p = nullptr;
    }
}



int main(int argc, const char * argv[]) {
    test1();
    test2();
    return 0;
}
