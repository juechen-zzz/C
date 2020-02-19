//
//  main.cpp
//  1_4  类模板派生普通类
//
//  Created by 倪浩鹏 on 2020/2/19.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class Father{
public:
    Father(){
        this->m_age = 0;
    }
    T m_age;
};

// 类去定义对象，继承的其中有模板，在分配内存的时候会出现问题，所以需要指定类型
class Son: public Father<int>{
public:
};

template<class T>
class Son1: public Father<T>{
public:
};

int main(int argc, const char * argv[]) {
    Father<int> *p = new Son;
    cout << p->m_age << endl;
    
    Father<int> *s = new Son1<int>;
    cout << s->m_age << endl;
    return 0;
}
