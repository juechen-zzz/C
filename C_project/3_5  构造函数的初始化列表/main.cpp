//
//  main.cpp
//  3_5  构造函数的初始化列表
//
//  Created by 倪浩鹏 on 2020/2/2.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;


class A{
public:
    A(int a){
        cout << "A(int a)..." << endl;
        m_a = a;
    }
    
    ~A(){
        cout << "~A()..." << endl;
    }
    
    void printA(){
        cout << "a = " << m_a << endl;
    }
    
    
private:
    int m_a;
    
};


// 构造函数的初始化列表，在构造函数的后面加上：并进行初始化
// 构造对象成员的顺序和初始化列表的顺序无关，与类中对象定义的顺序有关
// 构造函数不能够再调用构造函数，容易报错
// ABCD(int a, int b, int c, int d): m_abc(a, b, c), m_d(d)
class B{
public:
    // 法一
    B(int b, A &a1, A &a2) : m_a1(a1), m_a2(a2)     // 初始化一个类的对象成员
    {
        cout << "B(int b, A &a1, A &a2)..." << endl;
        m_b = b;
    }
    
    // 法二
    B(int b, int a1, int a2) : m_a1(a1), m_a2(a2) // m_b(b)：当m_b为常量时必须这样初始化
    {
        cout << "B(int b, int a1, int a2)..." << endl;
        m_b = b;
    }
    
    void printB(){
        cout << "b = " << m_b << endl;
        m_a1.printA();
        m_a2.printA();
    }
    
    ~B(){
        cout << "~B()..." << endl;
    }
private:
    int m_b;
    A m_a1;
    A m_a2;
};



int main(int argc, const char * argv[]) {
    A a1(10);
    A a2(20);
    // 法一
    B b(30, a1, a2);
    // 法二
    B b2(11, 22, 33);
    b2.printB();
    return 0;
}

