//
//  main.cpp
//  6_4  类的兼容性赋值原则
//
//  Created by 倪浩鹏 on 2020/2/10.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    1 子类对象可以直接赋值给父类对象     p = c;(Child c)
    2 子类对象可以当做父类对象使用
    3 子类对象可以直接初始化父类对象     Parent p = c;(Child c)
    4 父类指针可以直接指向子类对象      pp = &c;很重要，写接口经常用void printS(Parent *p)
    5 父类引用可以直接引用子类对象
 */

#include <iostream>
using namespace std;

class Parent{
public:
    void printS(){
        cout << this->a << endl;
    }
private:
    int a;
};

class Child: public Parent{
public:
    void printB(){
        printS();
        cout << this->b << endl;
    }
private:
    int b;
};

void printSS(Parent *p){
    p->printS();
}

int main(int argc, const char * argv[]) {
    Child c;
    Parent p;
    c.printB();
    
    Parent *pp = nullptr;
    Child *cp = nullptr;
//    cp = &c;
//    pp = &p;
    pp = &c;    // cp = &p不可行
    
    printSS(&p);
    printSS(&c);
    return 0;
}
