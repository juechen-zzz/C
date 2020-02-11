//
//  main.cpp
//  6_7  虚析构函数
//
//  Created by 倪浩鹏 on 2020/2/11.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout << "A()..." << endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "A String");
    }
    virtual void print(){
        cout << "A::" << this->p << endl;
    }
    virtual ~A(){
        cout << "~A()..." << endl;
        delete[] this->p;
        this->p = nullptr;
    }
private:
    char *p;
};

class B: public A{
public:
    B(){
        cout << "B()..." << endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "B String");
    }
    void print(){
        cout << "B::" << this->p << endl;
    }
    ~B(){
        cout << "~B()..." << endl;
        delete[] this->p;
        this->p = nullptr;
    }
private:
    char *p;
};

void func(A *p){
    p->print();         // 多态
    delete p;           // 这种写法原本只触发A的析构
}

void test(){
//    A a;
//    func(&a);
    
//    B b;
//    func(&b);
    B *b = new B;
    func(b);
}


int main(int argc, const char * argv[]) {
    test();
    return 0;
}

/*
    重载：在相同作用域下，函数重载
    重写：父类为虚函数，子类中的就是重写
    重定义：父子类中相同名字参数的函数
 */

