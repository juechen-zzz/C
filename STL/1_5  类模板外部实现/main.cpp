//
//  main.cpp
//  1_5  类模板外部实现
//
//  Created by 倪浩鹏 on 2020/2/19.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class Person{
public:
    // 重载左移操作符
    // friend ostream &operator<< <T>(ostream &os, Person<T> &p);
    // 普通友元函数
    // friend void PrintPerson(Person<T> &p);
    Person(T age, T id);
    void PrintS();
public:
    T age;
    T id;
};

template<class T>
Person<T>::Person(T age, T id){
    this->age = age;
    this->id = id;
}

template<class T>
void Person<T>::PrintS(){
    cout << "age: " << this->age << " id: " << this->id << endl;
}

//template<class T>
//void PrintPerson(Person<T> &p){
//    cout << "12312" << endl;
//}

//template<class T>
//ostream &operator<<(ostream &os, Person<T> &p){
//    os << "age: " << p.age << " id: " << p.id << endl;
//    return os;
//}

int main(int argc, const char * argv[]) {
    Person<int> p(10, 1);
    p.PrintS();
    // cout << p;
    // PrintPerson(p);
    return 0;
}

// 不要滥用友元
