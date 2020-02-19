//
//  Person.hpp
//  1_6  类模板外部实现（多文件）
//
//  Created by 倪浩鹏 on 2020/2/20.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
using namespace std;

template<class T>
class Person{
public:
    // 重载左移操作符
    template<class U>
    friend ostream &operator<<(ostream &os, Person<U> &p);
    // 普通友元函数
    template<class Z>
    friend void PrintPerson(Person<Z> &p);
    
    Person(T age, T id);
    void PrintS();
public:
    T age;
    T id;
};


// 类外成员函数实现
template<class T>
Person<T>::Person(T age, T id){
    this->age = age;
    this->id = id;
}

template<class T>
void Person<T>::PrintS(){
    cout << "age: " << this->age << " id: " << this->id << endl;
}


// 普通友元函数
template<class Z>
void PrintPerson(Person<Z> &p){
    cout << "12312" << endl;
}


// 重载左移操作符
template<class U>
ostream &operator<<(ostream &os, Person<U> &p){
    os << "age: " << p.age << " id: " << p.id << endl;
    return os;
}
#endif /* Person_hpp */
