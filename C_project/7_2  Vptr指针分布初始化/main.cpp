//
//  main.cpp
//  7_2  Vptr指针分布初始化
//
//  Created by 倪浩鹏 on 2020/2/12.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    Vptr指针是分布初始化，一开始指向父类的虚函数表，父类构造完后，再指向子类的虚函数表
 */

#include <iostream>
using namespace std;

class Parent{
public:
    Parent(int a){
        cout << "Parent(int a)" << endl;
        this->a = a;
        print();
    }
    virtual void print(){
        cout << "Parent::print()" << endl;
    }
private:
    int a;
};

class Child: public Parent{
public:
    // vptr指针的分布初始化，两个print代表不同时间段，一开始，先Parent(a)，所以上一个print是父类的
    Child(int a, int b): Parent(a){
        cout << "Child(int a, int b)" << endl;
        this->b = b;
        print();
    }
    virtual void print(){
        cout << "Child::print()" << endl;
    }
private:
    int b;
};

int main(int argc, const char * argv[]) {
    Parent *p = new Child(10, 20);
    p->print();
    
    return 0;
}
