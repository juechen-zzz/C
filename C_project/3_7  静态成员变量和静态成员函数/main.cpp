//
//  main.cpp
//  3_7  静态成员变量和静态成员函数
//
//  Created by 倪浩鹏 on 2020/2/2.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

// 静态成员变量在静态区开辟空间，并且只初始化一次

#include <iostream>
using namespace std;

class AA{
public:
    AA(int a, int b){
        m_a = a;
        m_b = b;
    }
    // static修饰的静态成员变量，在静态区开辟空间，只初始化1次
    static int m_c;
    int get_c(){
        m_c ++;
        return m_c;
    }
    
    // 因为要返回一个静态成员变量，需要用一个静态成员方法
    // 静态成员函数只能访问静态数据成员:
    //      非静态成员函数，在调用时this指针被当做参数传入，而静态成员函数属于类，而不属于对象，没有this指针
    static int &get_d(){
        return m_d;
    }
    
private:
    int m_a;
    int m_b;
    static int m_d;
};
// 静态h成员变量的初始化(public)，一定写在类的外部
int AA::m_c = 111;
int AA::m_d = 321;


void test(){
    static int m = 10;
    m++;
    cout << m << endl;
}

// 静态函数: 作用域只在这个文件
static void test1(){
    cout << "-----------------------" << endl;
}

int main(int argc, const char * argv[]) {
    // AA::m_c = 200 可以用这种方式访问m_c（public）,与a1,a2无关
    AA a1(10, 20);
    AA a2(100, 200);
    cout << a1.get_c() << endl;                 // 112
    cout << a2.get_c() << endl;                 // 113
    
    a1.get_d() = 323;
    
    
    test();
    test();
    test1();
    return 0;
}
