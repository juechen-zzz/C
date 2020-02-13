//
//  main.cpp
//  7_5  纯虚函数与多继承
//
//  Created by 倪浩鹏 on 2020/2/13.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class A{
public:
    virtual void func1(int a, int b) = 0;
};

class B{
public:
    virtual void func2(int a, int b) = 0;
};

class C: public A, public B{
public:
    virtual void func1(int a, int b){
        cout << "A:C" << endl;
    }
    virtual void func2(int a, int b){
        cout << "B:C" << endl;
    }
};

int main(int argc, const char * argv[]) {
    A *s1 = new C;
    s1->func1(1, 2);
    
    B *s2 = new C;
    s2->func2(1, 2);
    return 0;
}
