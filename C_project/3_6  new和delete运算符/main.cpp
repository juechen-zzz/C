//
//  main.cpp
//  3_6  new和delete
//
//  Created by 倪浩鹏 on 2020/2/2.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


// 在软件开发过程中，需要动态的分配和撤销内存空间，C++提供了new和delete运算符
// new和delete时运算符，不是函数，所以执行效率高
// new会在堆上初始化对象的构造函数，malloc则不行
// free并不能触发析构函数，delete可以
// 对应于C语言的malloc和free，但是malloc和free时函数（stdlib.h）

#include <iostream>
using namespace std;


class Test{
public:
    Test(int a, int b){
        m_a = a;
        m_b = b;
    }
    
    void printT(){
        cout << "111111111111" << endl;
    }
    
private:
    int m_a;
    int m_b;
};

// C语言
void test1(){
    // 创建指针
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    if (p != nullptr) {
        free(p);
        p = nullptr;
    }
    
    // 创建数组
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
    
    // 为类开辟空间，无法初始化，必须要用init函数
    Test *tp = (Test *)malloc(sizeof(Test));
    // tp->printT(); 会出错
    if (tp != nullptr) {
        free(tp);
        tp = nullptr;
    }
}

// C++语言
void test2(){
    // 创建指针
    int *p = new int;       // 开辟一个int的空间，返回地址
    // char *c = new char;
    *p = 10;
    if (p != nullptr) {
        delete p;
        p = nullptr;
    }
    
    // 创建数组
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
    
    // 为类开辟空间
    Test *tp = new Test(10, 20);
    tp->printT();
}




int main(int argc, const char * argv[]) {
    test1();
    test2();
    return 0;
}
