//
//  main.cpp
//  6_6  多态的定义及三个必要条件
//
//  Created by 倪浩鹏 on 2020/2/11.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    假设有几个似而不完全相同的对象，有时向他们发出同一个消息时，反应各不相同，分别进行不同的操作
    C++中：由继承而产生的相关的不同的类，其对象对同一信息作出不同的反应
 
    父类中和子类中有相同名字的成员方法，父类加virtual关键字，否则编译器会做一个保守的做法，调用父类的方法
 
    多态的三个条件：1 要有继承
                 2 要有虚函数重写
                 3 父类指针或引用指向子类对象
 */

#include <iostream>
using namespace std;

class Father{
public:
    Father(string kf){
        this->kf = kf;
    }
    virtual void fight(){                           // 表示修饰一个成员方法是虚函数
        cout << "Father:" << this->kf << endl;
    }
    string kf;
};

class Son: public Father{
public:
    Son(string kf): Father(kf){
    }
    virtual void fight(){                           // 此处的virtual无含义，只是增加可读性
        cout << "Son:" << this->kf << endl;
    }
};

// 在全局提供一个方法
void Fight1(Father *hero){
    hero->fight();
}

int main(int argc, const char * argv[]) {
//    Father f1("B");
//    f1.fight();
//
//    Son s1("A");
//    s1.fight();
    
    Father *f2 = new Father("D");
    // f2->fight();
    
    Son *s2 = new Son("C");
    // s2->fight();
    
    Fight1(f2);
    Fight1(s2);
    
    delete s2;
    delete f2;
    return 0;
}
