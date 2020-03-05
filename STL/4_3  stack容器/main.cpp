//
//  main.cpp
//  4_3  stack容器
//
//  Created by 倪浩鹏 on 2020/3/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    栈：先进后出，不能遍历(不提供迭代器)，不支持随机存取，只能从栈顶添加或删除元素
    push()/pop()    压栈/出栈
    top()           返回栈顶元素
    empty()/size()
 */

#include <iostream>
#include <stack>
using namespace std;

void PrintStack(stack<int> &s){
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void test1(){
    stack<int> s;
    s.push(10);
    s.push(20);
    stack<int> s2(s);
    PrintStack(s2);
}


class Person{
public:
private:
    string name;
};

void test2(){
    stack<Person*> p;
    Person p1, p2;
    p.push(&p1);
    p.push(&p2);
}

int main(int argc, const char * argv[]) {
    test2();
    return 0;
}
