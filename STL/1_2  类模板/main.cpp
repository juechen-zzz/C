//
//  main.cpp
//  1_2  类模板
//
//  Created by 倪浩鹏 on 2020/2/17.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class Person{
public:
    Person(T id, T age){
        this->id = id;
        this->age = age;
    }
    void printS(){
        cout << this->id << " " << this->age << endl;
    }
private:
    T id;
    T age;
};

int main(int argc, const char * argv[]) {
    // 函数模板在调用时可以自动类型推导，类模板必须显式指定类型
    Person<int> s1(1, 20);
    s1.printS();
    return 0;
}
