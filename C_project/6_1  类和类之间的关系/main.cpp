//
//  main.cpp
//  6_1  类和类之间的关系
//
//  Created by 倪浩鹏 on 2020/2/9.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


// 耦合度：高内聚，低耦合
//       高内聚：一个函数只有一个功能
//       低耦合：一个函数和别的函数关联越低越好



#include <iostream>
using namespace std;

class A{
public:
    void func(){
        cout << "funcA" << endl;
    }
    int a;
};

// 类B拥有类A的成员变量，B has A，类B依赖于类A
class B{
public:
    void func_B(){
        cout << "funcB" << endl;
    }
    A a;
};

// 类C的成员方法需要类A的形参， C use A，类C依赖于类A
class C{
public:
    void func_C(A *a){
        cout << "funcC" << endl;
    }
    A a;
};

// 类D继承于类A，这种耦合度最高
class D : public A
{
public:
    void func(){
        cout << a << endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

