//
//  main.cpp
//  2_2  类型转换
//
//  Created by 倪浩鹏 on 2020/2/21.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    1 static_cast       一般的转换，用于内置的数据类型或者具有继承关系的指针（引用）
    2 dynamic_cast      通常在基类和派生类之间转换使用
    3 const_cast        主要针对const的转换
    4 reinterpret_cast  用于进行没有任何关联之间的转换，比如一个字符指针转换为一个整形数
 */

#include <iostream>
using namespace std;

class Building{};
class Animal{};
class Cat: public Animal{};

// static_cast
void test1(){
    int a = 97;
    char c = static_cast<char>(a);
    cout << "char c = " << c << endl;
    
    // 转换指针
    Animal *animal = nullptr;
    Cat *cat = static_cast<Cat *>(animal);               // 父类指针转为子类指针，用&引用也可以
    Cat *cat2 = nullptr;
    Animal *animal2 = static_cast<Animal *>(cat2);       // 子类指针转为父类指针
}

// dynamic_cast     转换具有继承关系的指针或者引用，转换前会进行对象类型检查
void test2(){
    // int *a = nullptr;
    // char *c = dynamic_cast<char *>(a);
    
    // Animal *ani = nullptr;
    // Cat *cat = dynamic_cast<Cat *>(ani);            // 对象类型进行检查，只能子类指针转换为父类指针
    
    Cat *cat = nullptr;
    Animal *ani = dynamic_cast<Animal *>(cat);
    
}

// const_cast   指针 引用 对象指针
void test3(){
    int a = 10;
    const int &b = a;
    // b = 10;  此时不可修改
    int &c = const_cast<int &>(b);
    c = 20;
    cout << "a = " << a << endl;
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    return 0;
}
