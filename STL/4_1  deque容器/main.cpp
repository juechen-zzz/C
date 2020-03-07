//
//  main.cpp
//  4_1  deque容器
//
//  Created by 倪浩鹏 on 2020/3/3.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    vector是单口容器，deque是双口容器，分段连续，所以效率低，支持随机访问
    push_back()/pop_back()      从尾部放入/删除
    push_front()/pop_front()    从头部放入/删除
    front()/back()              返回第一个/最后一个元素，并非迭代器
 */

#include <iostream>
#include <deque>
using namespace std;


void PrintDeque(deque<int> &d){
    for (deque<int>::iterator i = d.begin(); i != d.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void Print1(int v){
    cout << v << " ";
}


// 初始化
void test1(){
    deque<int> d1;
    deque<int> d2(6, 2);
    for_each(d2.begin(), d2.end(), Print1);
    cout << endl;
    deque<int> d3(d2);
    deque<int> d4(d2.begin(), d2.end());
    PrintDeque(d4);
}


// 赋值、大小
void test2(){
    deque<int> d1;
    d1.assign(10, 5);
    
    deque<int> d2;
    d2.assign(d1.begin(), d1.end());
    PrintDeque(d2);
    
    deque<int> d3;
    d3 = d2;
    PrintDeque(d3);
}


// 插入和删除
void test3(){
    deque<int> d1;
    d1.push_back(11);
    d1.push_front(22);
    PrintDeque(d1);
}


int main(int argc, const char * argv[]) {
    test3();
    return 0;
}
