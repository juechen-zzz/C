//
//  main.cpp
//  7_3  纯虚函数和抽象类
//
//  Created by 倪浩鹏 on 2020/2/12.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    对应于Java中的接口
    语法：virtual 类型 函数名(参数) = 0;
 */

#include <iostream>
using namespace std;


// 如果一个类拥有纯虚函数，这种类称为抽象类，无法实例化
class Shape{
public:
    // 求面积，后面的0为纯语法概念，表示图形类声明一个方法为纯虚函数，没有函数的实现
    virtual double getA() = 0;
};


// 一个普通类继承拥有纯虚函数的类，必须要重写纯虚函数
// 不重写的话，子类还是一个抽象类
class Square: public Shape{
public:
    Square(int a){
        this->a = a;
    }
    virtual double getA(){
        return a * a;
    }
private:
    int a;
};


// 面向抽象类可以再写一个架构函数
void printS(Shape *p){
    p->getA();
}


// 业务层：面向抽象类编程，推荐使用第二种方法实例化
int main(int argc, const char * argv[]) {
    Shape *p = new Square(3);
    printS(p);
    return 0;
}
