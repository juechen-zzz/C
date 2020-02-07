//
//  main.cpp
//  5_3  自定义智能指针
//
//  Created by 倪浩鹏 on 2020/2/7.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    智能指针指能够自动回收的指针，不需要手动delete，类似于Java中的回收站机制
 */

#include <iostream>
#include <memory>
using namespace std;

class A{
public:
    A(int a){
        this->a = a;
    }
    void func(){
        cout << "a = " << this->a << endl;
    }
    ~A(){
        cout << "111111111111111111111111" << endl;
    }
private:
    int a;
};


class My_auto_ptr{
public:
    My_auto_ptr(A *ptr){this->ptr = ptr;}       // A*
    ~My_auto_ptr(){
        if (this->ptr != nullptr) {
            cout << "222222222222222222222222" << endl;
            delete this->ptr;
            this->ptr = nullptr;
        }
    }
    A * operator->(){return this->ptr;}
    A & operator*(){return *ptr;}
private:
    A *ptr;
};

int main(int argc, const char * argv[]) {
//    int *p = new int;
//    *p = 20;
//    delete p;
//
//    auto_ptr<int> ptr(new int);
//    *ptr = 20;
    
    A *ap = new A(10);
    ap->func();
    (*ap).func();
    
    auto_ptr<A> ptr_a(new A(10));       // 已废弃，会自动执行析构函数
    ptr_a->func();
    (*ptr_a).func();
    
    My_auto_ptr ptr_a_2(new A(20));
    ptr_a_2->func();
    (*ptr_a_2).func();
    return 0;
}
