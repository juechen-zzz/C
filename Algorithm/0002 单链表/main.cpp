//
//  main.cpp
//  0002 单链表
//
//  Created by 倪浩鹏 on 2020/3/12.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

// 打印单链表
void PrintNode(Node *p){
    while (p->next != nullptr) {
        cout << p->value << "-";
        p = p->next;
    }
    cout << p->value << endl;
}

// 增加节点
void addNode(Node *p, int addValue, int index){
    Node *newNode = new Node();
    newNode->value = addValue;
    newNode->next = nullptr;
    
    int i = 0;
    while (p->next != nullptr && i < (index - 1)) {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
}


int main(int argc, const char * argv[]) {
    Node *p = new Node();
    p->next = nullptr;
    p->value = 3;
    addNode(p, 5, 1);
    PrintNode(p);
    addNode(p, 7, 1);
    PrintNode(p);
    addNode(p, 4, 2);
    PrintNode(p);
    addNode(p, 1, 3);
    PrintNode(p);
}
