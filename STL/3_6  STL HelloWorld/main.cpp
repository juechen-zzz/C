//
//  main.cpp
//  3_6  STL HelloWorld
//
//  Created by 倪浩鹏 on 2020/2/27.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
#include <vector>           // 动态数组
#include <algorithm>        // 算法
using namespace std;


void PrintVector(int v){
    cout << v << " ";
}

void test1(){
    vector<int> v;          // 定义一个容器并且指定存放的元素类型
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    // 通过STL提供的for_each算法，容器提供迭代器，vector<int>::iterator为迭代器类型
    // vector<int>::iterator pBegin = v.begin();
    // 容器可能存在基础数据类型，也可能是自定义数据类型
    for_each(v.begin(), v.end(), PrintVector);
    cout << endl;
}


// 容器也可以存在自定义数据类型
class Person{
public:
    Person(){}
    Person(int age, int id){
        this->age = age;
        this->id = id;
    }
    int GetAge(){return this->age;}
    int GetID(){return this->id;}
private:
    int age;
    int id;
};

void test2(){
    vector<Person> v;
    Person p1(10, 1);
    Person p2(20, 2);
    Person p3(40, 3);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    // 遍历，*i就是vector<>里面的类型
    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++) {
        cout << (*i).GetID() << " " << (*i).GetAge() << endl;
    }
}


int main(int argc, const char * argv[]) {
    test1();
    test2();
    return 0;
}
