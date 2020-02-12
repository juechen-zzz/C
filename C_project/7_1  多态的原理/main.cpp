//
//  main.cpp
//  7_1  多态的原理
//
//  Created by 倪浩鹏 on 2020/2/12.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    如果说一个类中有virtualg虚函数关键字，在编译器给这个对象开辟空间的时候，会默认增加一个指针vptr
 */

#include <iostream>
using namespace std;

class Parent{
public:
    Parent(){}
    Parent(int a){
        this->a = a;
    }
    virtual void func(int a){
        cout << "Parent func: " << a << endl;
    }
    void func(int a, int b, int c){
        cout << "Parent func: " << a+b+c << endl;
    }
private:
    int a;
};

class Child: public Parent{
public:
    Child(){}
    Child(int a, int b): Parent(a){
        this->b = b;
    }
    virtual void func(int a){
        cout << "Child func: " << a << endl;
    }
    void func(int a, int b){
        cout << "Child func2: " << a+b << endl;
    }
private:
    int b;
};

void myfunc(Parent &p){
    p.func(10);
}

int main(int argc, const char * argv[]) {
    Child c;
    myfunc(c);
    c.func(10, 20);
    return 0;
}
