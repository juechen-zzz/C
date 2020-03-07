//
//  main.cpp
//  4_4  queue容器
//
//  Created by 倪浩鹏 on 2020/3/4.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    队列：先进先出，从一端插入，在另一端删除，不能进行遍历,不提供迭代器，不支持随机访问
    push()      从队尾插入（入队）
    pop()       从队头删除（出队）
    front()/back()
 */

#include <iostream>
#include <queue>
using namespace std;


void test1(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.back() << endl;
    
    queue<int> q2;
    q2 = q;
    cout << q2.back() << endl;
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
